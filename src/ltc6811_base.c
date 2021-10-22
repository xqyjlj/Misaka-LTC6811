/**
 * @file ltc6811_base.c
 * @brief
 * @author xqyjlj (xqyjlj@126.com)
 * @version 0.0
 * @date 2021-07-21
 * @copyright Copyright © 2020-2021 xqyjlj<xqyjlj@126.com>
 *
 * *********************************************************************************
 * @par ChangeLog:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2021-07-21 <td>0.0     <td>xqyjlj  <td>内容
 * </table>
 * *********************************************************************************
 */

#include "misaka_device/ltc6811_base.h"

static uint16_t pec_table[256] = {0x0000, 0xC599, 0xCEAB, 0x0B32, 0xD8CF, 0x1D56, 0x1664, 0xD3FD,
                                  0xF407, 0x319E, 0x3AAC, 0xFF35, 0x2CC8, 0xE951, 0xE263, 0x27FA,
                                  0xAD97, 0x680E, 0x633C, 0xA6A5, 0x7558, 0xB0C1, 0xBBF3, 0x7E6A,
                                  0x5990, 0x9C09, 0x973B, 0x52A2, 0x815F, 0x44C6, 0x4FF4, 0x8A6D,
                                  0x5B2E, 0x9EB7, 0x9585, 0x501C, 0x83E1, 0x4678, 0x4D4A, 0x88D3,
                                  0xAF29, 0x6AB0, 0x6182, 0xA41B, 0x77E6, 0xB27F, 0xB94D, 0x7CD4,
                                  0xF6B9, 0x3320, 0x3812, 0xFD8B, 0x2E76, 0xEBEF, 0xE0DD, 0x2544,
                                  0x02BE, 0xC727, 0xCC15, 0x098C, 0xDA71, 0x1FE8, 0x14DA, 0xD143,
                                  0xF3C5, 0x365C, 0x3D6E, 0xF8F7, 0x2B0A, 0xEE93, 0xE5A1, 0x2038,
                                  0x07C2, 0xC25B, 0xC969, 0x0CF0, 0xDF0D, 0x1A94, 0x11A6, 0xD43F,
                                  0x5E52, 0x9BCB, 0x90F9, 0x5560, 0x869D, 0x4304, 0x4836, 0x8DAF,
                                  0xAA55, 0x6FCC, 0x64FE, 0xA167, 0x729A, 0xB703, 0xBC31, 0x79A8,
                                  0xA8EB, 0x6D72, 0x6640, 0xA3D9, 0x7024, 0xB5BD, 0xBE8F, 0x7B16,
                                  0x5CEC, 0x9975, 0x9247, 0x57DE, 0x8423, 0x41BA, 0x4A88, 0x8F11,
                                  0x057C, 0xC0E5, 0xCBD7, 0x0E4E, 0xDDB3, 0x182A, 0x1318, 0xD681,
                                  0xF17B, 0x34E2, 0x3FD0, 0xFA49, 0x29B4, 0xEC2D, 0xE71F, 0x2286,
                                  0xA213, 0x678A, 0x6CB8, 0xA921, 0x7ADC, 0xBF45, 0xB477, 0x71EE,
                                  0x5614, 0x938D, 0x98BF, 0x5D26, 0x8EDB, 0x4B42, 0x4070, 0x85E9,
                                  0x0F84, 0xCA1D, 0xC12F, 0x04B6, 0xD74B, 0x12D2, 0x19E0, 0xDC79,
                                  0xFB83, 0x3E1A, 0x3528, 0xF0B1, 0x234C, 0xE6D5, 0xEDE7, 0x287E,
                                  0xF93D, 0x3CA4, 0x3796, 0xF20F, 0x21F2, 0xE46B, 0xEF59, 0x2AC0,
                                  0x0D3A, 0xC8A3, 0xC391, 0x0608, 0xD5F5, 0x106C, 0x1B5E, 0xDEC7,
                                  0x54AA, 0x9133, 0x9A01, 0x5F98, 0x8C65, 0x49FC, 0x42CE, 0x8757,
                                  0xA0AD, 0x6534, 0x6E06, 0xAB9F, 0x7862, 0xBDFB, 0xB6C9, 0x7350,
                                  0x51D6, 0x944F, 0x9F7D, 0x5AE4, 0x8919, 0x4C80, 0x47B2, 0x822B,
                                  0xA5D1, 0x6048, 0x6B7A, 0xAEE3, 0x7D1E, 0xB887, 0xB3B5, 0x762C,
                                  0xFC41, 0x39D8, 0x32EA, 0xF773, 0x248E, 0xE117, 0xEA25, 0x2FBC,
                                  0x0846, 0xCDDF, 0xC6ED, 0x0374, 0xD089, 0x1510, 0x1E22, 0xDBBB,
                                  0x0AF8, 0xCF61, 0xC453, 0x01CA, 0xD237, 0x17AE, 0x1C9C, 0xD905,
                                  0xFEFF, 0x3B66, 0x3054, 0xF5CD, 0x2630, 0xE3A9, 0xE89B, 0x2D02,
                                  0xA76F, 0x62F6, 0x69C4, 0xAC5D, 0x7FA0, 0xBA39, 0xB10B, 0x7492,
                                  0x5368, 0x96F1, 0x9DC3, 0x585A, 0x8BA7, 0x4E3E, 0x450C, 0x8095
                                 };
static uint8_t send_data[LTC6811_DEVICE_NUM * 8 + 4];                 //SPI发送数据寄存器
static uint8_t receive_data[LTC6811_DEVICE_NUM * 8 + 4];                   //SPI接收数据寄存器
static uint16_t pec_data;

misaka_ltc6811_struct misaka_ltc6811_device_object[LTC6811_DEVICE_NUM];                         //设备数据结构体

/**
 * @brief
 */
void misaka_ltc6811_init_pec15_table()
{
    uint16_t remainder, bit, i;
    for (i = 0; i < 256; i++)
    {
        remainder = i << 7;
        for (bit = 8; bit > 0; bit--)
        {
            if (remainder & 0x4000)
            {
                remainder = ((remainder << 1));
                remainder = (remainder ^ LTC6811_CRC15_POLY);
            }
            else
            {
                remainder = ((remainder << 1));
            }
        }
        pec_table[i] = remainder & 0xFFFF;
    }
}
/**
 * @brief
 * @param  data             desc
 * @param  len              desc
 * @return uint16_t @c
 */
static uint16_t misaka_ltc6811_PEC15(uint8_t* data, uint16_t len)
{
    uint16_t remainder, address;
    uint16_t i;
    remainder = 16;//PEC seed
    for (i = 0; i < len; i++)
    {
        address = ((remainder >> 7) ^ data[i]) & 0xff;//calculate PEC table address
        remainder = (remainder << 8) ^ pec_table[address];
    }
    return (remainder * 2); //The CRC15 has a 0 in the LSB so the final value must be multiplied by 2
}
/**
 * @brief
 * @param  cmd              desc
 * @param  data             desc
 */
static void misaka_ltc6811_Init_cmd(uint16_t cmd, misaka_cmd_struct* data)
{
    uint8_t i[2];
    uint16_t j;
    (*data).stru.cmd[0] = cmd >> 8;
    (*data).stru.cmd[1] = cmd & 0x00FF;
    i[0] = cmd >> 8;
    i[1] = cmd & 0x00FF;
    j = misaka_ltc6811_PEC15(i, 2);
    (*data).stru.cmd_pec[0] = j >> 8;
    (*data).stru.cmd_pec[1] = j & 0x00FF;
}

/**
 * @brief
 * @param  cmd              desc
 * @return uint8_t @c
 */
static uint8_t misaka_ltc6811_Send_cmd(uint16_t cmd)  //发送命令
{
    misaka_cmd_struct _cmd;
    misaka_ltc6811_Init_cmd(cmd, &_cmd);

    send_data[0] = _cmd.data[0];
    send_data[1] = _cmd.data[1];
    send_data[2] = _cmd.data[2];
    send_data[3] = _cmd.data[3];
    return misaka_ltc6811_transmit_receive(send_data, receive_data, 4);
}
/**
 * @brief
 * @param  P                desc
 * @return uint8_t @c
 */
static uint8_t misaka_ltc6811_Read_cmd(uint16_t cmd)
{
    uint8_t i, j;

    misaka_cmd_struct _cmd;
    misaka_ltc6811_Init_cmd(cmd, &_cmd);

    send_data[0] = _cmd.data[0];
    send_data[1] = _cmd.data[1];
    send_data[2] = _cmd.data[2];
    send_data[3] = _cmd.data[3];
    for (i = 0; i < LTC6811_DEVICE_NUM; i++)
    {
        for (j = 0; j < 8; j++)
        {
            send_data[i * 8 + j + 4] = 0xFF;
        }
    }
    return misaka_ltc6811_transmit_receive(send_data, receive_data, LTC6811_DEVICE_NUM * 8 + 4);
}
/**
 * @brief
 * @param  P                desc
 * @return uint8_t @c
 */
static uint8_t misaka_ltc6811_Write_cmd(uint16_t cmd)
{
    misaka_cmd_struct _cmd;
    misaka_ltc6811_Init_cmd(cmd, &_cmd);

    send_data[0] = _cmd.data[0];
    send_data[1] = _cmd.data[1];
    send_data[2] = _cmd.data[2];
    send_data[3] = _cmd.data[3];
    return misaka_ltc6811_transmit_receive(send_data, receive_data, LTC6811_DEVICE_NUM * 8 + 4);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_wakeidle(void)
{
    uint8_t i;
    for (i = 0; i < LTC6811_DEVICE_NUM; i++)
    {
        send_data[i * 4 + 0] = 0xAA;
        send_data[i * 4 + 1] = 0xAA;
        send_data[i * 4 + 2] = 0xAA;
        send_data[i * 4 + 3] = 0xAA;
    }
    return misaka_ltc6811_transmit_receive(send_data, receive_data, 4 * LTC6811_DEVICE_NUM);
}
/**
 * @brief
 * @param  P                desc
 * @param  DeviceNum        desc
 * @return uint8_t @c
 */
static uint8_t misaka_ltc6811_Move_data(uint8_t P[], uint8_t DeviceNum)
{
    uint8_t i[8];
    i[0] = receive_data[4 + (LTC6811_DEVICE_NUM - 1 - DeviceNum) * 8];
    i[1] = receive_data[5 + (LTC6811_DEVICE_NUM - 1 - DeviceNum) * 8];
    i[2] = receive_data[6 + (LTC6811_DEVICE_NUM - 1 - DeviceNum) * 8];
    i[3] = receive_data[7 + (LTC6811_DEVICE_NUM - 1 - DeviceNum) * 8];
    i[4] = receive_data[8 + (LTC6811_DEVICE_NUM - 1 - DeviceNum) * 8];
    i[5] = receive_data[9 + (LTC6811_DEVICE_NUM - 1 - DeviceNum) * 8];
    pec_data = misaka_ltc6811_PEC15(i, 6);
    i[6] = pec_data >> 8;
    i[7] = pec_data & 0x00FF;
    if ((i[6] == receive_data[10 + (LTC6811_DEVICE_NUM - 1 - DeviceNum) * 8]) && (i[7] == receive_data[11 + (LTC6811_DEVICE_NUM - 1 - DeviceNum) * 8]))
    {
        P[0] = i[0];
        P[1] = i[1];
        P[2] = i[2];
        P[3] = i[3];
        P[4] = i[4];
        P[5] = i[5];
        return 0;
    }
    else
    {
        P[0] = 0;
        P[1] = 0;
        P[2] = 0;
        P[3] = 0;
        P[4] = 0;
        P[5] = 0;
        return 1;
    }
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_wrcfga(void)
{
    for (uint8_t i = 0; i < LTC6811_DEVICE_NUM; i++)
    {
        pec_data = misaka_ltc6811_PEC15(misaka_ltc6811_device_object[i].cfgr, 6);
        misaka_ltc6811_device_object[i].cfgr[6] = pec_data >> 8;
        misaka_ltc6811_device_object[i].cfgr[7] = pec_data & 0x00FF;
    }
    for (uint8_t i = 0; i < LTC6811_DEVICE_NUM; i++)
    {
        for (uint8_t j = 0; j < 8; j++)
        {
            send_data[i * 8 + j + 4] = misaka_ltc6811_device_object[i].cfgr[j];
        }
    }
    return misaka_ltc6811_Write_cmd(LTC6811_WRCFGA);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_rdcfga(void)
{
    //TODO 待完成
    return misaka_ltc6811_Read_cmd(LTC6811_RDCFGA);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_rdcva(void)
{
    uint8_t status;
    status = misaka_ltc6811_Read_cmd(LTC6811_RDCVA);
    for (uint8_t i = 0; i < LTC6811_DEVICE_NUM; i++)
    {
        misaka_ltc6811_Move_data(misaka_ltc6811_device_object[i].cvar, i);
    }
    return status;
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_rdcvb(void)
{
    uint8_t status;
    status = misaka_ltc6811_Read_cmd(LTC6811_RDCVB);
    for (uint8_t i = 0; i < LTC6811_DEVICE_NUM; i++)
    {
        misaka_ltc6811_Move_data(misaka_ltc6811_device_object[i].cvbr, i);
    }
    return status;
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_rdcvc(void)
{
    uint8_t status;
    status = misaka_ltc6811_Read_cmd(LTC6811_RDCVC);
    for (uint8_t i = 0; i < LTC6811_DEVICE_NUM; i++)
    {
        misaka_ltc6811_Move_data(misaka_ltc6811_device_object[i].cvcr, i);
    }
    return status;
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_rdcvd(void)
{
    uint8_t status;
    status = misaka_ltc6811_Read_cmd(LTC6811_RDCVD);
    for (uint8_t i = 0; i < LTC6811_DEVICE_NUM; i++)
    {
        misaka_ltc6811_Move_data(misaka_ltc6811_device_object[i].cvdr, i);
    }
    return status;
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_rdauxa(void)
{
    uint8_t status;
    status = misaka_ltc6811_Read_cmd(LTC6811_RDAUXA);
    for (uint8_t i = 0; i < LTC6811_DEVICE_NUM; i++)
    {
        misaka_ltc6811_Move_data(misaka_ltc6811_device_object[i].avar, i);
    }
    return status;
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_rdauxb(void)
{
    uint8_t status;
    status = misaka_ltc6811_Read_cmd(LTC6811_RDAUXB);
    for (uint8_t i = 0; i < LTC6811_DEVICE_NUM; i++)
    {
        misaka_ltc6811_Move_data(misaka_ltc6811_device_object[i].avbr, i);
    }
    return status;
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_rdstata(void)
{
    uint8_t status;
    status = misaka_ltc6811_Read_cmd(LTC6811_RDSTATA);
    for (uint8_t i = 0; i < LTC6811_DEVICE_NUM; i++)
    {
        misaka_ltc6811_Move_data(misaka_ltc6811_device_object[i].star, i);
    }
    return status;
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_rdstatb(void)
{
    uint8_t status;
    status = misaka_ltc6811_Read_cmd(LTC6811_RDSTATB);
    for (uint8_t i = 0; i < LTC6811_DEVICE_NUM; i++)
    {
        misaka_ltc6811_Move_data(misaka_ltc6811_device_object[i].stbr, i);
    }
    return status;
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_wrsctrl(void)
{
    //TODO 待完成
    return  misaka_ltc6811_Write_cmd(LTC6811_WRSCTRL);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_wrpwm(void)
{
    //TODO 待完成
    return  misaka_ltc6811_Write_cmd(LTC6811_WRPWM);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_rdsctrl(void)
{
    //TODO 待完成
    return  misaka_ltc6811_Read_cmd(LTC6811_RDSCTRL);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_rdpwm(void)
{
    //TODO 待完成
    return  misaka_ltc6811_Read_cmd(LTC6811_RDPWM);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_stsctrl(void)
{
    //TODO 待完成
    return  misaka_ltc6811_Send_cmd(LTC6811_STSCTRL);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_clrsctrl(void)
{
    //TODO 待完成
    return  misaka_ltc6811_Send_cmd(LTC6811_CLRSCTRL);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_adcv(uint16_t cmd)
{
    return misaka_ltc6811_Send_cmd(LTC6811_ADCV | cmd);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_adow(uint16_t cmd)
{
    return misaka_ltc6811_Send_cmd(LTC6811_ADOW | cmd);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_cvst(uint16_t cmd)
{
    return misaka_ltc6811_Send_cmd(LTC6811_CVST | cmd);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_adol(uint16_t cmd)
{
    return misaka_ltc6811_Send_cmd(LTC6811_ADOL | cmd);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_adax(uint16_t cmd)
{
    return misaka_ltc6811_Send_cmd(LTC6811_ADAX | cmd);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_adaxd(uint16_t cmd)
{
    return misaka_ltc6811_Send_cmd(LTC6811_ADAXD | cmd);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_axst(uint16_t cmd)
{
    return misaka_ltc6811_Send_cmd(LTC6811_AXST | cmd);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_adstat(uint16_t cmd)
{
    return misaka_ltc6811_Send_cmd(LTC6811_ADSTAT | cmd);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_adstatd(uint16_t cmd)
{
    return misaka_ltc6811_Send_cmd(LTC6811_ADSTATD | cmd);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_statst(uint16_t cmd)
{
    return misaka_ltc6811_Send_cmd(LTC6811_STATST | cmd);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_adcvax(uint16_t cmd)
{
    return misaka_ltc6811_Send_cmd(LTC6811_ADCVAX | cmd);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_adcvsc(uint16_t cmd)
{
    return misaka_ltc6811_Send_cmd(LTC6811_ADCVSC | cmd);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_clrcell(void)
{
    return  misaka_ltc6811_Send_cmd(LTC6811_CLRCELL);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_clraux(void)
{
    return  misaka_ltc6811_Send_cmd(LTC6811_CLRAUX);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_clrstat(void)
{
    return  misaka_ltc6811_Send_cmd(LTC6811_CLRSTAT);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_pladc(void)
{
    //TODO
    return  misaka_ltc6811_Send_cmd(LTC6811_PLADC);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_diagn(void)
{
    //TODO
    return  misaka_ltc6811_Send_cmd(LTC6811_DIAGN);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_wrcomm(void)
{
    //TODO
    return  misaka_ltc6811_Write_cmd(LTC6811_WRCOMM);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_rdcomm(void)
{
    //TODO
    return  misaka_ltc6811_Read_cmd(LTC6811_RDCOMM);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cmd_stcomm(void)
{
    //TODO
    return  misaka_ltc6811_Send_cmd(LTC6811_STCOMM);
}