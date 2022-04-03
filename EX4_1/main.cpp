#include <stdio.h> /* Standard input/output definitions */
#include <stdlib.h>
#include <string.h> /* String function definitions */
#include <stdbool.h>
#include <unistd.h> /* UNIX standard function definitions */
#include <fcntl.h> /* File control definitions */
#include <errno.h> /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <pthread.h>
#define MODBUS_FRAME_SIZE_MAX 13
#define MODBUS_CMD_NUM 6
#define MODBUS_RESP_NUM_MAX 20
typedef struct {
unsigned char data[MODBUS_FRAME_SIZE_MAX];
unsigned char realsize;
}modbus_info_t;

const modbus_info_t Query_Cmd[1] = {
{{0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0xC4, 0x0B}, 8}
};
const modbus_info_t Fan_Cmd[2] = {
{{0x01, 0x06, 0x00, 0x02, 0x00, 0x00, 0x28, 0x0A}, 8},
{{0x01, 0x06, 0x00, 0x02, 0x19, 0xD8, 0x23, 0xC0}, 8}
};
const modbus_info_t Shade_Cmd[3] = {
{{0x01, 0x06, 0x00, 0x04, 0x19, 0xD8, 0xC3, 0xC1}, 8},
{{0x01, 0x06, 0x00, 0x03, 0x19, 0xD8, 0x72, 0x00}, 8},
{{0x01, 0x10, 0x00, 0x03, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0xB3, 0xBA}, 13}
};
const modbus_info_t Film_Cmd[3] = {
{{0x01, 0x06, 0x00, 0x06, 0x19, 0xD8, 0x62, 0x01}, 8},
{{0x01, 0x06, 0x00, 0x05, 0x19, 0xD8, 0x92, 0x01}, 8},
{{0x01, 0x10, 0x00, 0x05, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x33, 0x90}, 13}
};
const modbus_info_t Sprayer_Cmd[2] = {
{{0x01, 0x06, 0x00, 0x07, 0x00, 0x00, 0x38, 0x0B}, 8},
{{0x01, 0x06, 0x00, 0x07, 0x19, 0xD8, 0x33, 0xC1}, 8}
};
const modbus_info_t Light_Cmd[2] = {
{{0x01, 0x06, 0x00, 0x08, 0x00, 0x00, 0x08, 0x08}, 8},
{{0x01, 0x06, 0x00, 0x08, 0x19, 0xD8, 0x03, 0xC2}, 8}
};
const modbus_info_t *Cmd_Tab[MODBUS_CMD_NUM] = {Query_Cmd, Fan_Cmd, Shade_Cmd, Film_Cmd, Sprayer_Cmd, Light_Cmd};
const Cmd_Act_Num[MODBUS_CMD_NUM] = {1, 2, 3, 3, 2, 2};

int ser_fd; //serial port file descriptor

void open_port(const char * sdev)
{
    struct termios newtio;

    if (sdev == NULL)
        exit(1);
    ser_fd = open(sdev, O_RDWR | O_NOCTTY | O_NDELAY);
    if (ser_fd == -1)
    {
        perror("open_port: Unable to open serail port - ");
    }
    else
    {
        fcntl(ser_fd, F_SETFL, 0);//enable rx timeout control
    }
    if (tcgetattr(ser_fd, &newtio) != 0)
    {
        perror("Setup serial port failure!\n");
        exit(1);
    }

    newtio.c_cflag |= CLOCAL | CREAD;
    newtio.c_cflag &= ~PARENB;
    newtio.c_cflag &= ~CSTOPB;
    newtio.c_cflag &= ~CSIZE;
    newtio.c_cflag |= CS8;
    newtio.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    newtio.c_oflag &= ~OPOST;

    cfsetispeed(&newtio, B4800);
    cfsetospeed(&newtio, B4800);
    newtio.c_cc[VMIN] = 0;
    newtio.c_cc[VTIME] = 50;
    tcflush(ser_fd,TCIFLUSH);

    if((tcsetattr(ser_fd,TCSANOW,&newtio))!=0)
    {
        perror("com set error");
        exit(1);
    }
}

void disp_menu(int * cmd, int * act)
{

    printf("\n**************************************************\n");
    printf("* 0. query status (act: 0) *\n");
    printf("* 1. control fan (act: 0-CLOSE 1-OPEN) *\n");
    printf("* 2. control shade (act: 0-CLOSE 1-OPEN 2-STOP) *\n");
    printf("* 3. control film (act: 0-CLOSE 1-OPEN 2-STOP) *\n");
    printf("* 4. control spry (act: 0-CLOSE 1-OPEN) *\n");
    printf("* 5. control light (act: 0-CLOSE 1-OPEN) *\n");
    printf("* 6. exit (act: any number) *\n");
    printf("**************************************************\n");
    printf("input choice(cmd,action):");

    do
    {
        scanf("%d,%d", cmd, act);
        if (*cmd >= 0 && *cmd <= 6)
        {
            if (*act < 0)
                *act = 0;
            if (*act > 2)
                *act = 2;
            break;
        }
        printf("input again:");
    }while(1);
}

bool gh_modbus_cmd(int cmd_idx, int act_idx, char * resp, int * resp_len)
{
    int k, nread;
    if (cmd_idx < 0 || cmd_idx > 6) return false;
    if (act_idx < 0 || act_idx >= Cmd_Act_Num[cmd_idx]) return false;
    write(ser_fd, Cmd_Tab[cmd_idx][act_idx].data, Cmd_Tab[cmd_idx][act_idx].realsize);
    k = 0;
    do
    {
        nread=read(ser_fd, &resp[k], MODBUS_RESP_NUM_MAX-k);
        k += nread;
    }
    while (nread > 0);
    *resp_len = k;
    return true;
}

int main(int argc, char * argv[])
{
    int nread, i, k;
    int cmd, act;
    unsigned char buff[MODBUS_RESP_NUM_MAX];
    pthread_t th_serx;
    if (argc != 2)
    {
        printf("usage: this_file serial_port_dev_filepath\n");
        exit(1);
    }
    open_port(argv[1]);
    do
    {
        disp_menu(&cmd, &act);
        if (cmd == 6) break;
        if (gh_modbus_cmd(cmd, act, buff, &k))
        {
            printf("rx data:");
            for (i=0; i<k; i++)
            {
                printf("%2X ", buff[i]);
            }
            printf("\n");
        }
        else
        {
            printf("command not valid!\n");
        }
    }while (1);
    close(ser_fd);
}
