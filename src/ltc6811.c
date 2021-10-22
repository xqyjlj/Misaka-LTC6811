/**
 * @file misaka_ltc6811.c
 * @brief
 * @author xqyjlj (xqyjlj@126.com)
 * @version 0.0
 * @date 2021-07-22
 * @copyright Copyright © 2020-2021 xqyjlj<xqyjlj@126.com>
 *
 * *********************************************************************************
 * @par ChangeLog:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2021-07-22 <td>0.0     <td>xqyjlj  <td>内容
 * </table>
 * *********************************************************************************
 */
#include "misaka_device/ltc6811.h"

/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_wakeidle(void)
{
    return misaka_ltc6811_cmd_wakeidle();
}
/**
 * @brief
 * @param  cfgr             desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_wrcfga(misaka_ltc6811_cfgr_struct* cfgr)
{
    uint16_t vuv = (((cfgr->vuv * 10) / 16) - 1);
    uint16_t vov = ((cfgr->vov * 10) / 16);
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        misaka_ltc6811_device_object[i].cfgr[0] = cfgr->gpiox | cfgr->refon | cfgr->dten | cfgr->adcopt;
        misaka_ltc6811_device_object[i].cfgr[1] = 0x00FF & vuv;
        misaka_ltc6811_device_object[i].cfgr[2] = ((0x000F & vov) << 4) + ((0x0F00 & vuv) >> 8);
        misaka_ltc6811_device_object[i].cfgr[3] = (0x0FF0 & vov) >> 4;
        misaka_ltc6811_device_object[i].cfgr[4] = 0x00FF & 0x0000;
        misaka_ltc6811_device_object[i].cfgr[5] = cfgr->dcto | ((0x0F00 & 0x0000) >> 8);
    }
    return misaka_ltc6811_cmd_wrcfga();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_rdcfga(void)
{
    return misaka_ltc6811_cmd_rdcfga();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_rdcva(void)
{
    return misaka_ltc6811_cmd_rdcva();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_rdcvb(void)
{
    return misaka_ltc6811_cmd_rdcvb();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_rdcvc(void)
{
    return misaka_ltc6811_cmd_rdcvc();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_rdcvd(void)
{
    return misaka_ltc6811_cmd_rdcvd();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_rdauxa(void)
{
    return misaka_ltc6811_cmd_rdauxa();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_rdauxb(void)
{
    return misaka_ltc6811_cmd_rdauxb();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_rdstata(void)
{
    return misaka_ltc6811_cmd_rdstata();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_rdstatb(void)
{
    return misaka_ltc6811_cmd_rdstatb();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_wrsctrl(void)
{
    return misaka_ltc6811_cmd_wrsctrl();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_wrpwm(void)
{
    return misaka_ltc6811_cmd_wrpwm();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_rdsctrl(void)
{
    return misaka_ltc6811_cmd_rdsctrl();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_rdpwm(void)
{
    return misaka_ltc6811_cmd_rdpwm();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_stsctrl(void)
{
    return misaka_ltc6811_cmd_stsctrl();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_clrsctrl(void)
{
    return misaka_ltc6811_cmd_clrsctrl();
}
/**
 * @brief
 * @param  md               desc
 * @param  dcp              desc
 * @param  ch               desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_adcv(uint16_t md, uint8_t dcp, uint8_t ch)
{
    return misaka_ltc6811_cmd_adcv(md | dcp | ch);
}
/**
 * @brief
 * @param  md               desc
 * @param  pup              desc
 * @param  dcp              desc
 * @param  ch               desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_adow(uint16_t md, uint8_t pup, uint8_t dcp, uint8_t ch)
{
    return misaka_ltc6811_cmd_adow(md | pup | dcp | ch);
}
/**
 * @brief
 * @param  md               desc
 * @param  st               desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cvst(uint16_t md, uint8_t st)
{
    return misaka_ltc6811_cmd_cvst(md | st);
}
/**
 * @brief
 * @param  md               desc
 * @param  dcp              desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_adol(uint16_t md, uint8_t dcp)
{
    return misaka_ltc6811_cmd_adol(md | dcp);
}
/**
 * @brief
 * @param  md               desc
 * @param  chg              desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_adax(uint16_t md, uint8_t chg)
{
    return misaka_ltc6811_cmd_adax(md | chg);
}
/**
 * @brief
 * @param  md               desc
 * @param  chg              desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_adaxd(uint16_t md, uint8_t chg)
{
    return misaka_ltc6811_cmd_adaxd(md | chg);
}
/**
 * @brief
 * @param  md               desc
 * @param  st               desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_axst(uint16_t md, uint8_t st)
{
    return misaka_ltc6811_cmd_axst(md | st);
}
/**
 * @brief
 * @param  md               desc
 * @param  chst             desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_adstat(uint16_t md, uint8_t chst)
{
    return misaka_ltc6811_cmd_adstat(md | chst);
}
/**
 * @brief
 * @param  md               desc
 * @param  chst             desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_adstatd(uint16_t md, uint8_t chst)
{
    return misaka_ltc6811_cmd_adstatd(md | chst);
}
/**
 * @brief
 * @param  md               desc
 * @param  st               desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_statst(uint16_t md, uint8_t st)
{
    return misaka_ltc6811_cmd_statst(md | st);
}
/**
 * @brief
 * @param  md               desc
 * @param  dcp              desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_adcvax(uint16_t md, uint8_t dcp)
{
    return misaka_ltc6811_cmd_adcvax(md | dcp);
}
/**
 * @brief
 * @param  md               desc
 * @param  dcp              desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_adcvsc(uint16_t md, uint8_t dcp)
{
    return misaka_ltc6811_cmd_adcvsc(md | dcp);
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_clrcell(void)
{
    return misaka_ltc6811_cmd_clrcell();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_clraux(void)
{
    return misaka_ltc6811_cmd_clraux();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_clrstat(void)
{
    return misaka_ltc6811_cmd_clrstat();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_pladc(void)
{
    return misaka_ltc6811_cmd_pladc();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_diagn(void)
{
    return misaka_ltc6811_cmd_diagn();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_wrcomm(void)
{
    return misaka_ltc6811_cmd_wrcomm();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_rdcomm(void)
{
    return misaka_ltc6811_cmd_rdcomm();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_stcomm(void)
{
    return misaka_ltc6811_cmd_stcomm();
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_calculate_cell_voltage(void)
{
    uint8_t status = 0;
    status += misaka_ltc6811_rdcva();
    status += misaka_ltc6811_rdcvb();
    status += misaka_ltc6811_rdcvc();
    status += misaka_ltc6811_rdcvd();
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++) //将电压缓存在电压辅助数组里
    {
        misaka_ltc6811_device_object[i].cell_volt[0] = (((uint16_t)misaka_ltc6811_device_object[i].cvar[1]) << 8) + misaka_ltc6811_device_object[i].cvar[0];
        misaka_ltc6811_device_object[i].cell_volt[1] = (((uint16_t)misaka_ltc6811_device_object[i].cvar[3]) << 8) + misaka_ltc6811_device_object[i].cvar[2];
        misaka_ltc6811_device_object[i].cell_volt[2] = (((uint16_t)misaka_ltc6811_device_object[i].cvar[5]) << 8) + misaka_ltc6811_device_object[i].cvar[4];
        misaka_ltc6811_device_object[i].cell_volt[3] = (((uint16_t)misaka_ltc6811_device_object[i].cvbr[1]) << 8) + misaka_ltc6811_device_object[i].cvbr[0];
        misaka_ltc6811_device_object[i].cell_volt[4] = (((uint16_t)misaka_ltc6811_device_object[i].cvbr[3]) << 8) + misaka_ltc6811_device_object[i].cvbr[2];
        misaka_ltc6811_device_object[i].cell_volt[5] = (((uint16_t)misaka_ltc6811_device_object[i].cvbr[5]) << 8) + misaka_ltc6811_device_object[i].cvbr[4];
        misaka_ltc6811_device_object[i].cell_volt[6] = (((uint16_t)misaka_ltc6811_device_object[i].cvcr[1]) << 8) + misaka_ltc6811_device_object[i].cvcr[0];
        misaka_ltc6811_device_object[i].cell_volt[7] = (((uint16_t)misaka_ltc6811_device_object[i].cvcr[3]) << 8) + misaka_ltc6811_device_object[i].cvcr[2];
        misaka_ltc6811_device_object[i].cell_volt[8] = (((uint16_t)misaka_ltc6811_device_object[i].cvcr[5]) << 8) + misaka_ltc6811_device_object[i].cvcr[4];
        misaka_ltc6811_device_object[i].cell_volt[9] = (((uint16_t)misaka_ltc6811_device_object[i].cvdr[1]) << 8) + misaka_ltc6811_device_object[i].cvdr[0];
        misaka_ltc6811_device_object[i].cell_volt[10] = (((uint16_t)misaka_ltc6811_device_object[i].cvdr[3]) << 8) + misaka_ltc6811_device_object[i].cvdr[2];
        misaka_ltc6811_device_object[i].cell_volt[11] = (((uint16_t)misaka_ltc6811_device_object[i].cvdr[5]) << 8) + misaka_ltc6811_device_object[i].cvdr[4];
    }
    return status;
}
/**
 * @brief
 * @param  md               desc
 * @param  dcp              desc
 * @param  ch               desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_read_all_cell_voltage(uint16_t md, uint8_t dcp, uint8_t ch)
{
    uint8_t status = 0;
    status += misaka_ltc6811_adcv(md, dcp, ch);
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_calculate_cell_voltage();
    return status;
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_calculate_auxiliary_voltage(void)
{
    uint8_t status = 0;
    status += misaka_ltc6811_rdauxa();
    status += misaka_ltc6811_rdauxb();
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        misaka_ltc6811_device_object[i].gpio_volt[0] = (((uint16_t)misaka_ltc6811_device_object[i].avar[1]) << 8) + misaka_ltc6811_device_object[i].avar[0];
        misaka_ltc6811_device_object[i].gpio_volt[1] = (((uint16_t)misaka_ltc6811_device_object[i].avar[3]) << 8) + misaka_ltc6811_device_object[i].avar[2];
        misaka_ltc6811_device_object[i].gpio_volt[2] = (((uint16_t)misaka_ltc6811_device_object[i].avar[5]) << 8) + misaka_ltc6811_device_object[i].avar[4];
        misaka_ltc6811_device_object[i].gpio_volt[3] = (((uint16_t)misaka_ltc6811_device_object[i].avbr[1]) << 8) + misaka_ltc6811_device_object[i].avbr[0];
        misaka_ltc6811_device_object[i].gpio_volt[4] = (((uint16_t)misaka_ltc6811_device_object[i].avbr[3]) << 8) + misaka_ltc6811_device_object[i].avbr[2];
        misaka_ltc6811_device_object[i].ref_volt = (((uint16_t)misaka_ltc6811_device_object[i].avbr[5]) << 8) + misaka_ltc6811_device_object[i].avbr[4];
    }
    return status;
}
/**
 * @brief
 * @param  md               desc
 * @param  chg              desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_read_all_auxiliary_voltage(uint16_t md, uint8_t chg)
{
    uint8_t status = 0;
    status += misaka_ltc6811_adax(md, chg);
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_calculate_auxiliary_voltage();
    return status;
}
/**
 * @brief
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_calculate_status(void)
{
    uint8_t status = 0;
    status += misaka_ltc6811_rdstata();
    status += misaka_ltc6811_rdstatb();
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        misaka_ltc6811_device_object[i].soc_volt = (((uint16_t)misaka_ltc6811_device_object[i].star[1]) << 8) + misaka_ltc6811_device_object[i].star[0];
        misaka_ltc6811_device_object[i].total_volt = misaka_ltc6811_device_object[i].soc_volt * 20;
        misaka_ltc6811_device_object[i].itmp_volt = (((uint16_t)misaka_ltc6811_device_object[i].star[3]) << 8) + misaka_ltc6811_device_object[i].star[2];
        misaka_ltc6811_device_object[i].itm = ((misaka_ltc6811_device_object[i].itmp_volt * 100) / 75) - 273;
        misaka_ltc6811_device_object[i].va_volt = (((uint16_t)misaka_ltc6811_device_object[i].star[5]) << 8) + misaka_ltc6811_device_object[i].star[4];
        misaka_ltc6811_device_object[i].vd_volt = (((uint16_t)misaka_ltc6811_device_object[i].stbr[1]) << 8) + misaka_ltc6811_device_object[i].stbr[0];
        misaka_ltc6811_device_object[i].cv_flag = (((uint32_t)misaka_ltc6811_device_object[i].stbr[4]) << 16) + (((uint16_t)misaka_ltc6811_device_object[i].stbr[3]) << 8) + misaka_ltc6811_device_object[i].stbr[2];
        misaka_ltc6811_device_object[i].rev = (misaka_ltc6811_device_object[i].stbr[5] & 0xF0) >> 4;
        misaka_ltc6811_device_object[i].mux_fail = (misaka_ltc6811_device_object[i].stbr[5] & 0x02) >> 1;
        misaka_ltc6811_device_object[i].thsd = (misaka_ltc6811_device_object[i].stbr[5] & 0x01) >> 0;
    }
    return status;
}
/**
 * @brief
 * @param  md               desc
 * @param  chst             desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_read_all_status(uint16_t md, uint8_t chst)
{
    uint8_t status = 0;
    status += misaka_ltc6811_adstat(md, chst);
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_calculate_status();
    return status;
}
/**
 * @brief
 * @param  md               desc
 * @param  st               desc
 * @param  stc              desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_cell_voltage_self_test(uint16_t md, uint8_t st, uint16_t stc)
{
    uint8_t status = 0;
    status += misaka_ltc6811_clrcell();
    status += misaka_ltc6811_cvst(md, st);
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_calculate_cell_voltage();
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        for (uint8_t j = 0; j < 12; j++)
        {
            if (misaka_ltc6811_device_object[i].cell_volt[j] != stc)
            {
                status ++;
            }
        }
    }
    return status;
}
/**
 * @brief
 * @param  md               desc
 * @param  st               desc
 * @param  stc              desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_auxiliary_voltage_self_test(uint16_t md, uint8_t st, uint16_t stc)
{
    uint8_t status = 0;
    status += misaka_ltc6811_clraux();
    status += misaka_ltc6811_axst(md, st);
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_calculate_auxiliary_voltage();
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        for (uint8_t j = 0; j < 5; j++)
        {
            if (misaka_ltc6811_device_object[i].gpio_volt[j] != stc)
            {
                status ++;
            }
        }
        if (misaka_ltc6811_device_object[i].ref_volt != stc)
        {
            status ++;
        }
    }
    return status;
}
/**
 * @brief
 * @param  md               desc
 * @param  st               desc
 * @param  stc              desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_status_voltage_self_test(uint16_t md, uint8_t st, uint16_t stc)
{
    uint8_t status = 0;
    status += misaka_ltc6811_clrstat();
    status += misaka_ltc6811_statst(md, st);
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_calculate_status();
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        if (misaka_ltc6811_device_object[i].soc_volt != stc)
        {
            status ++;
        }
        if (misaka_ltc6811_device_object[i].itmp_volt != stc)
        {
            status ++;
        }
        if (misaka_ltc6811_device_object[i].va_volt != stc)
        {
            status ++;
        }
        if (misaka_ltc6811_device_object[i].vd_volt != stc)
        {
            status ++;
        }
    }
    return status;
}

/**
 * @brief
 * @param  md               desc
 * @param  st               desc
 * @param  stc              desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_status_self_test(uint16_t md, uint8_t st, uint16_t stc)
{
    uint8_t status = 0;
    status += misaka_ltc6811_clrstat();
    status += misaka_ltc6811_statst(md, st);
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_diagn();
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_calculate_status();
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        if (misaka_ltc6811_device_object[i].soc_volt != stc)
        {
            status ++;
        }
        if (misaka_ltc6811_device_object[i].itmp_volt != stc)
        {
            status ++;
        }
        if (misaka_ltc6811_device_object[i].va_volt != stc)
        {
            status ++;
        }
        if (misaka_ltc6811_device_object[i].vd_volt != stc)
        {
            status ++;
        }
        if (misaka_ltc6811_device_object[i].mux_fail != 0)
        {
            status ++;
        }
    }
    return status;
}
/**
 * @brief
 * @param  md               desc
 * @param  dcp              desc
 * @param  ch               desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_open_wire_check(uint16_t md, uint8_t dcp, uint8_t ch)
{
    uint8_t status = 0;
    status += misaka_ltc6811_clrcell();
    /*上拉电流源*/
    status += misaka_ltc6811_adow(md, LTC6811_PUP1, dcp, ch);
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_adow(md, LTC6811_PUP1, dcp, ch);
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_adow(md, LTC6811_PUP1, dcp, ch);

    status += misaka_ltc6811_calculate_cell_voltage();

    /*下拉电流源*/
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_clrcell();
    status += misaka_ltc6811_adow(md, LTC6811_PUP0, dcp, ch);
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_adow(md, LTC6811_PUP0, dcp, ch);
    misaka_ltc6811_delay_ms(misaka_ltc6811_delay_unit);
    status += misaka_ltc6811_adow(md, LTC6811_PUP0, dcp, ch);

    status += misaka_ltc6811_rdcva();
    status += misaka_ltc6811_rdcvb();
    status += misaka_ltc6811_rdcvc();
    status += misaka_ltc6811_rdcvd();

    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        misaka_ltc6811_device_object[i].open_wires = 0;
        if ((misaka_ltc6811_device_object[i].cell_volt[0] == 0))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 0);
        }
        if ((misaka_ltc6811_device_object[i].cell_volt[0] - ((((uint16_t)misaka_ltc6811_device_object[i].cvar[1]) << 8) + misaka_ltc6811_device_object[i].cvar[0]) < -4000))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 1);
        }
        if ((misaka_ltc6811_device_object[i].cell_volt[1] - ((((uint16_t)misaka_ltc6811_device_object[i].cvar[3]) << 8) + misaka_ltc6811_device_object[i].cvar[2]) < -4000))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 2);
        }
        if ((misaka_ltc6811_device_object[i].cell_volt[2] - ((((uint16_t)misaka_ltc6811_device_object[i].cvar[5]) << 8) + misaka_ltc6811_device_object[i].cvar[4]) < -4000))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 3);
        }
        if ((misaka_ltc6811_device_object[i].cell_volt[3] - ((((uint16_t)misaka_ltc6811_device_object[i].cvbr[1]) << 8) + misaka_ltc6811_device_object[i].cvbr[0]) < -4000))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 4);
        }
        if ((misaka_ltc6811_device_object[i].cell_volt[4] - ((((uint16_t)misaka_ltc6811_device_object[i].cvbr[3]) << 8) + misaka_ltc6811_device_object[i].cvbr[2]) < -4000))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 5);
        }
        if ((misaka_ltc6811_device_object[i].cell_volt[5] - ((((uint16_t)misaka_ltc6811_device_object[i].cvbr[5]) << 8) + misaka_ltc6811_device_object[i].cvbr[4]) < -4000))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 6);
        }
        if ((misaka_ltc6811_device_object[i].cell_volt[6] - ((((uint16_t)misaka_ltc6811_device_object[i].cvcr[1]) << 8) + misaka_ltc6811_device_object[i].cvcr[0]) < -4000))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 7);
        }
        if ((misaka_ltc6811_device_object[i].cell_volt[7] - ((((uint16_t)misaka_ltc6811_device_object[i].cvcr[3]) << 8) + misaka_ltc6811_device_object[i].cvcr[2]) < -4000))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 8);
        }
        if ((misaka_ltc6811_device_object[i].cell_volt[8] - ((((uint16_t)misaka_ltc6811_device_object[i].cvcr[5]) << 8) + misaka_ltc6811_device_object[i].cvcr[4]) < -4000))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 9);
        }
        if ((misaka_ltc6811_device_object[i].cell_volt[9] - ((((uint16_t)misaka_ltc6811_device_object[i].cvdr[1]) << 8) + misaka_ltc6811_device_object[i].cvdr[0]) < -4000))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 10);
        }
        if ((misaka_ltc6811_device_object[i].cell_volt[10] - ((((uint16_t)misaka_ltc6811_device_object[i].cvdr[3]) << 8) + misaka_ltc6811_device_object[i].cvdr[2]) < -4000))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 11);
        }
        if ((((((uint16_t)misaka_ltc6811_device_object[i].cvdr[5]) << 8) + misaka_ltc6811_device_object[i].cvdr[4]) == 0) && ((0x0800 & misaka_ltc6811_device_object[i].cell_select) != 0))
        {
            status ++;
            misaka_ltc6811_device_object[i].open_wires |= (0x01 << 12);
        }
    }

    return status;
}
/**
 * @brief
 * @return uint8_t @c
 */
static uint8_t misaka_ltc6811_balance_group_Disable()
{
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        misaka_ltc6811_device_object[i].cfgr[4] = 0x00FF & 0x0000;
        misaka_ltc6811_device_object[i].cfgr[5] &= 0xF0;
        misaka_ltc6811_device_object[i].cfgr[5] |= ((0x0F00 & 0x0000) >> 8);
    }
    return misaka_ltc6811_cmd_wrcfga();
}
/**
 * @brief
 * @return uint8_t @c
 */
static uint8_t misaka_ltc6811_balance_group_Odd()
{
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        misaka_ltc6811_device_object[i].cfgr[4] = 0x00FF & 0x0555;
        misaka_ltc6811_device_object[i].cfgr[5] &= 0xF0;
        misaka_ltc6811_device_object[i].cfgr[5] |= ((0x0F00 & 0x0555) >> 8);
    }
    return misaka_ltc6811_cmd_wrcfga();
}
/**
 * @brief
 * @return uint8_t @c
 */
static uint8_t misaka_ltc6811_balance_group_Even()
{
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {

        misaka_ltc6811_device_object[i].cfgr[4] = 0x00FF & 0x0AAA;
        misaka_ltc6811_device_object[i].cfgr[5] &= 0xF0;
        misaka_ltc6811_device_object[i].cfgr[5] |= ((0x0F00 & 0x0AAA) >> 8);
    }
    return misaka_ltc6811_cmd_wrcfga();
}
/**
 * @brief
 * @param  group            0:  关闭均衡
 *                          1:  奇数均衡
 *                          2:  偶数均衡
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_balance_group(uint8_t group)
{
    uint8_t status = 0;
    if (group == 0)
    {
        status = misaka_ltc6811_balance_group_Disable();
    }
    else if (group == 1)
    {
        status = misaka_ltc6811_balance_group_Odd();
    }
    else if (group == 2)
    {
        status = misaka_ltc6811_balance_group_Even();
    }
    return status;
}
/**
 * @brief
 * @param  balance_thresholddesc
 */
void misaka_ltc6811_dcc_flag(uint8_t balance_threshold)
{
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        misaka_ltc6811_device_object[i].dcc_flag = 0x0000;    //清零
        for (uint8_t j = 0; j < 12; j++)
        {
            if ((misaka_ltc6811_device_object[i].cell_select & (0x01 >> j)) != 0)
            {
                if (((misaka_ltc6811_device_object[i].cell_volt[j] - misaka_ltc6811_device_object[i].cell_volt_min >= balance_threshold) ||
                        (misaka_ltc6811_device_object[i].cell_volt_max - misaka_ltc6811_device_object[i].cell_volt[j] >= balance_threshold)))
                {
                    misaka_ltc6811_device_object[i].dcc_flag |= (0x01 >> j);
                }
            }

        }
    }
}
/**
 * @brief
 */
void misaka_ltc6811_max_cell_voltage()
{
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        misaka_ltc6811_device_object[i].cell_volt_max = misaka_ltc6811_device_object[i].cell_volt[0];
        for (uint8_t j = 0; j < 12; j++)
        {
            if ((misaka_ltc6811_device_object[i].cell_select & (0x01 >> j)) != 0)
            {
                if (misaka_ltc6811_device_object[i].cell_volt[j] > misaka_ltc6811_device_object[i].cell_volt_max)
                {
                    misaka_ltc6811_device_object[i].cell_volt_max = misaka_ltc6811_device_object[i].cell_volt[j];
                }
            }
        }
    }
}
/**
 * @brief
 */
void misaka_ltc6811_min_cell_voltage()
{
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        misaka_ltc6811_device_object[i].cell_volt_min = misaka_ltc6811_device_object[i].cell_volt[0];
        for (uint8_t j = 0; j < 12; j++)
        {
            if ((misaka_ltc6811_device_object[i].cell_select & (0x01 >> j)) != 0)
            {
                if (misaka_ltc6811_device_object[i].cell_volt[j] < misaka_ltc6811_device_object[i].cell_volt_min)
                {
                    misaka_ltc6811_device_object[i].cell_volt_min = misaka_ltc6811_device_object[i].cell_volt[j];
                }
            }
        }
    }
}
/**
 * @brief
 */
void misaka_ltc6811_max_min_cell_voltage()
{
    misaka_ltc6811_max_cell_voltage();
    misaka_ltc6811_min_cell_voltage();
    for (uint8_t i = 0; i < LTC6811_DeviceNUM; i++)
    {
        misaka_ltc6811_device_object[i].cell_volt_delta =
            misaka_ltc6811_device_object[i].cell_volt_max - misaka_ltc6811_device_object[i].cell_volt_min;
    }
}
/**
 * @brief
 * @param  md               desc
 * @param  st               desc
 * @param  stc              desc
 * @return uint8_t @c
 */
uint8_t misaka_ltc6811_self_test(uint16_t md, uint8_t st, uint16_t stc)
{
    uint8_t status = 0;
    status += misaka_ltc6811_cell_voltage_self_test(md, st, stc);
    status += misaka_ltc6811_auxiliary_voltage_self_test(md, st, stc);
    status += misaka_ltc6811_status_self_test(md, st, stc);
    return status;
}
