/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011,2012 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    stm32_otg.h
 * @brief   STM32 OTG registers layout header.
 *
 * @addtogroup USB
 * @{
 */

#ifndef _STM32_OTG_H_
#define _STM32_OTG_H_

/**
 * @brief   Number of the implemented endpoints.
 * @details This value does not include the endpoint 0 that is always present.
 */
#define STM32_OTG_ENDOPOINTS_NUMBER     3

/**
 * @brief   Host channel registers group.
 */
typedef struct {
  volatile uint32_t HCCHAR;     /**< @brief Host channel characteristics
                                            register.                       */
  volatile uint32_t resvd8;
  volatile uint32_t HCINT;      /**< @brief Host channel interrupt register.*/
  volatile uint32_t HCINTMSK;   /**< @brief Host channel interrupt mask
                                            register.                       */
  volatile uint32_t HCTSIZ;     /**< @brief Host channel transfer size
                                            register.                       */
  volatile uint32_t resvd14;
  volatile uint32_t resvd18;
  volatile uint32_t resvd1c;
} stm32_otg_host_chn_t;

/**
 * @brief   Device input endpoint registers group.
 */
typedef struct {
  volatile uint32_t DIEPCTL;    /**< @brief Device control IN endpoint control
                                            register.                       */
  volatile uint32_t resvd4;
  volatile uint32_t DIEPINT;    /**< @brief Device IN endpoint interrupt
                                            register.                       */
  volatile uint32_t resvdC;
  volatile uint32_t DIEPTSIZ;   /**< @brief Device IN endpoint transfer size
                                            register.                       */
  volatile uint32_t resvd14;
  volatile uint32_t DTXFSTS;    /**< @brief Device IN endpoint transmit FIFO
                                            status register.                */
  volatile uint32_t resvd1C;
} stm32_otg_in_ep_t;

/**
 * @brief   Device output endpoint registers group.
 */
typedef struct {
  volatile uint32_t DOEPCTL;    /**< @brief Device control OUT endpoint control
                                            register.                       */
  volatile uint32_t resvd4;
  volatile uint32_t DOEPINT;    /**< @brief Device OUT endpoint interrupt
                                            register.                       */
  volatile uint32_t resvdC;
  volatile uint32_t DOEPTSIZ;   /**< @brief Device OUT endpoint transfer size
                                            register.                       */
  volatile uint32_t resvd14;
  volatile uint32_t resvd18;
  volatile uint32_t resvd1C;
} stm32_t_out_ep_t;

/**
 * @brief   USB registers memory map.
 */
typedef struct {
  volatile uint32_t GOTGCTL;    /**< @brief OTG control and status register.*/
  volatile uint32_t GOTGINT;    /**< @brief OTG interrupt register.         */
  volatile uint32_t GAHBCFG;    /**< @brief AHB configuration register.     */
  volatile uint32_t GUSBCFG;    /**< @brief USB configuration register.     */
  volatile uint32_t GRSTCTL;    /**< @brief Reset register size.            */
  volatile uint32_t GINTSTS;    /**< @brief Interrupt register.             */
  volatile uint32_t GINTMSK;    /**< @brief Interrupt mask register.        */
  volatile uint32_t GRXSTSR;    /**< @brief Receive status debug read
                                            register.                       */
  volatile uint32_t GRXSTSP;    /**< @brief Receive status read/pop
                                            register.                       */
  volatile uint32_t GRXFSIZ;    /**< @brief Receive FIFO size register.     */
  volatile uint32_t DIEPTXF0;   /**< @brief endpoint 0 transmit FIFO size
                                            register.                       */
  volatile uint32_t HNPTXSTS;   /**< @brief non-periodic transmit FIFO/queue
                                            status register.                */
  volatile uint32_t resvd30;
  volatile uint32_t resvd34;
  volatile uint32_t GCCFG;      /**< @brief General core configuration.     */
  volatile uint32_t CID;        /**< @brief Core ID register.               */
  volatile uint32_t resvd58[48];
  volatile uint32_t HPTXFSIZ;   /**< @brief Host periodic transmit FIFO size
                                            register.                       */
  volatile uint32_t DIEPTXF[15];/**< @brief Ddevice IN endpoint transmit FIFO
                                            size registers.                 */
  volatile uint32_t resvd140[176];
  volatile uint32_t HCFG;       /**< @brief Host configuration register.    */
  volatile uint32_t HFIR;       /**< @brief Host frame interval register.   */
  volatile uint32_t HFNUM;      /**< @brief Host frame number/frame time
                                            Remaining register.             */
  volatile uint32_t resvd40C;
  volatile uint32_t HPTXSTS;    /**< @brief Host periodic transmit FIFO/queue
                                            status register.                */
  volatile uint32_t HAINT;      /**< @brief Host all channels interrupt
                                            register.                       */
  volatile uint32_t HAINTMSK;   /**< @brief Host all channels interrupt mask
                                            register.                       */
  volatile uint32_t resvd41C[9];
  volatile uint32_t HPRT;       /**< @brief Host port control and status
                                            register.                       */
  volatile uint32_t resvd444[47];
  stm32_otg_host_chn_t hc[16];  /**< @brief Host channels array.            */
  volatile uint32_t resvd700[64];
  volatile uint32_t DCFG;       /**< @brief Device configuration register.  */
  volatile uint32_t DCTL;       /**< @brief Device control register.        */
  volatile uint32_t DSTS;       /**< @brief Device status register.         */
  volatile uint32_t resvd80C;
  volatile uint32_t DIEPMSK;    /**< @brief Device IN endpoint common
                                            interrupt mask register.        */
  volatile uint32_t DOEPMSK;    /**< @brief Device OUT endpoint common
                                            interrupt mask register.        */
  volatile uint32_t DAINT;      /**< @brief Device all endpoints interrupt
                                            register.                       */
  volatile uint32_t DAINTMSK;   /**< @brief Device all endpoints interrupt
                                            mask register.                  */
  volatile uint32_t resvd820;
  volatile uint32_t resvd824;
  volatile uint32_t DVBUSDIS;   /**< @brief Device VBUS Discharge time
                                            register.                       */
  volatile uint32_t DVBUSPULSE; /**< @brief Device VBUS Pulsing time
                                            register.                       */
  volatile uint32_t resvd830;
  volatile uint32_t DIEPEMPMSK; /**< @brief Device IN endpoint FIFO empty
                                            interrupt mask register.        */
  volatile uint32_t resvd838;
  volatile uint32_t resvd83C;
  volatile uint32_t resvd840[16];
  volatile uint32_t resvd880[16];
  volatile uint32_t resvd8C0[16];
  stm32_otg_in_ep_t ie[16];     /**< @brief Input endpoints.                */
  stm32_t_out_ep_t oe[16];      /**< @brief Output endpoints.               */
  volatile uint32_t resvdD00[64];
  volatile uint32_t PCGCCTL;    /**< @brief Power and clock gating control
                                            register.                       */
  volatile uint32_t resvdE04[127];
} stm32_otg_t;

/**
 * @name GOTGCTL register bit definitions
 * @{
 */
#define GOTGCTL_BSVLD           (1U<<19)    /**< B-Session Valid.           */
#define GOTGCTL_ASVLD           (1U<<18)    /**< A-Session Valid.           */
#define GOTGCTL_DBCT            (1U<<17)    /**< Long/Short debounce time.  */
#define GOTGCTL_CIDSTS          (1U<<16)    /**< Connector ID status.       */
#define GOTGCTL_DHNPEN          (1U<<11)    /**< Device HNP enabled.        */
#define GOTGCTL_HSHNPEN         (1U<<10)    /**< Host Set HNP enable.       */
#define GOTGCTL_HNPRQ           (1U<<9)     /**< HNP request.               */
#define GOTGCTL_HNGSCS          (1U<<8)     /**< Host negotiation success.  */
#define GOTGCTL_SRQ             (1U<<1)     /**< Session request.           */
#define GOTGCTL_SRQSCS          (1U<<0)     /**< Session request success.   */
/** @} */

/**
 * @name GOTGINT register bit definitions
 * @{
 */
#define GOTGINT_DBCDNE          (1U<<19)    /**< Debounce done.             */
#define GOTGINT_ADTOCHG         (1U<<18)    /**< A-Device timeout change.   */
#define GOTGINT_HNGDET          (1U<<17)    /**< Host negotiation detected. */
#define GOTGINT_HNSSCHG         (1U<<9)     /**< Host negotiation success
                                                 status change.             */
#define GOTGINT_SRSSCHG         (1U<<8)     /**< Session request success
                                                 status change.             */
#define GOTGINT_SEDET           (1U<<2)     /**< Session end detected.      */
/** @} */

/**
 * @name GAHBCFG register bit definitions
 * @{
 */
#define GAHBCFG_PTXFELVL        (1U<<8)     /**< Periodic TxFIFO empty
                                                 level.                     */
#define GAHBCFG_TXFELVL         (1U<<7)     /**< non-periodic TxFIFO empty
                                                 level.                     */
#define GAHBCFG_GINTMSK         (1U<<0)     /**< Global interrupt mask.     */
/** @} */

/**
 * @name GUSBCFG register bit definitions
 * @{
 */
#define GUSBCFG_CTXPKT          (1U<<31)    /**< Corrupt Tx packet.         */
#define GUSBCFG_FDMOD           (1U<<30)    /**< Force Device Mode.         */
#define GUSBCFG_FHMOD           (1U<<29)    /**< Force Host Mode.           */
#define GUSBCFG_TRDT_MASK       (15U<<10)   /**< USB Turnaround time field
                                                 mask.                      */
#define GUSBCFG_TRDT(n)         ((n##U)<<10)/**< USB Turnaround time field
                                                 value.                     */
#define GUSBCFG_HNPCAP          (1U<<9)     /**< HNP-Capable.               */
#define GUSBCFG_SRPCAP          (1U<<8)     /**< SRP-Capable.               */
#define GUSBCFG_PHYSEL          (1U<<6)     /**< USB 2.0 High-Speed PHY or
                                                 USB 1.1 Full-Speed serial
                                                 transceiver Select.        */
#define GUSBCFG_TOCAL_MASK      (7U<<0)     /**< HS/FS timeout calibration
                                                 field mask.                */
#define GUSBCFG_TOCAL(n)        ((n##U)<<0) /**< HS/FS timeout calibration
                                                 field value.               */
/** @} */

/**
 * @name GRSTCTL register bit definitions
 * @{
 */
#define GRSTCTL_AHBIDL          (1U<<31)    /**< AHB Master Idle.           */
#define GRSTCTL_TXFNUM_MASK     (31U<<6)    /**< TxFIFO number field mask.  */
#define GRSTCTL_TXFNUM(n)       ((n##U)<<6) /**< TxFIFO number field value. */
#define GRSTCTL_TXFFLSH         (1U<<5)     /**< TxFIFO flush.              */
#define GRSTCTL_RXFFLSH         (1U<<4)     /**< RxFIFO flush.              */
#define GRSTCTL_FCRST           (1U<<2)     /**< Host frame counter reset.  */
#define GRSTCTL_HSRST           (1U<<1)     /**< HClk soft reset.           */
#define GRSTCTL_CSRST           (1U<<0)     /**< Core soft reset.           */
/** @} */

/**
 * @name GINTSTS register bit definitions
 * @{
 */
#define GINTSTS_WKUPINT         (1U<<31)    /**< Resume/Remote wakeup
                                                 detected interrupt.        */
#define GINTSTS_SRQINT          (1U<<30)    /**< Session request/New session
                                                 detected interrupt.        */
#define GINTSTS_DISCINT         (1U<<29)    /**< Disconnect detected
                                                 interrupt.                 */
#define GINTSTS_CIDSCHG         (1U<<28)    /**< Connector ID status change.*/
#define GINTSTS_PTXFE           (1U<<26)    /**< Periodic TxFIFO empty.     */
#define GINTSTS_HCINT           (1U<<25)    /**< Host channels interrupt.   */
#define GINTSTS_HPRTINT         (1U<<24)    /**< Host port interrupt.       */
#define GINTSTS_IPXFR           (1U<<21)    /**< Incomplete periodic
                                                 transfer.                  */
#define GINTSTS_IISOOXFR        (1U<<21)    /**< Incomplete isochronous OUT
                                                 transfer.                  */
#define GINTSTS_IISOIXFR        (1U<<20)    /**< Incomplete isochronous IN
                                                 transfer.                  */
#define GINTSTS_OEPINT          (1U<<19)    /**< OUT endpoints interrupt.   */
#define GINTSTS_IEPINT          (1U<<18)    /**< IN endpoints interrupt.    */
#define GINTSTS_EOPF            (1U<<15)    /**< End of periodic frame
                                                 interrupt.                 */
#define GINTSTS_ISOODRP         (1U<<14)    /**< Isochronous OUT packet
                                                 dropped interrupt.         */
#define GINTSTS_ENUMDNE         (1U<<13)    /**< Enumeration done.          */
#define GINTSTS_USBRST          (1U<<12)    /**< USB reset.                 */
#define GINTSTS_USBSUSP         (1U<<11)    /**< USB suspend.               */
#define GINTSTS_ESUSP           (1U<<10)    /**< Early suspend.             */
#define GINTSTS_GONAKEFF        (1U<<7)     /**< Global OUT NAK effective.  */
#define GINTSTS_GINAKEFF        (1U<<6)     /**< Global IN non-periodic NAK
                                                 effective.                 */
#define GINTSTS_NPTXFE          (1U<<5)     /**< Non-periodic TxFIFO empty. */
#define GINTSTS_RXFLVL          (1U<<4)     /**< RxFIFO non-empty.          */
#define GINTSTS_SOF             (1U<<3)     /**< Start of frame.            */
#define GINTSTS_OTGINT          (1U<<2)     /**< OTG interrupt.             */
#define GINTSTS_MMIS            (1U<<1)     /**< Mode Mismatch interrupt.   */
#define GINTSTS_CMOD            (1U<<0)     /**< Current mode of operation. */
/** @} */

/**
 * @name GINTMSK register bit definitions
 * @{
 */
#define GINTMSK_WKUM            (1U<<31)    /**< Resume/remote wakeup
                                                 detected interrupt mask.   */
#define GINTMSK_SRQM            (1U<<30)    /**< Session request/New session
                                                 detected interrupt mask.   */
#define GINTMSK_DISCM           (1U<<29)    /**< Disconnect detected
                                                 interrupt mask.            */
#define GINTMSK_CIDSCHGM        (1U<<28)    /**< Connector ID status change
                                                 mask.                      */
#define GINTMSK_PTXFEM          (1U<<26)    /**< Periodic TxFIFO empty mask.*/
#define GINTMSK_HCM             (1U<<25)    /**< Host channels interrupt
                                                 mask.                      */
#define GINTMSK_HPRTM           (1U<<24)    /**< Host port interrupt mask.  */
#define GINTMSK_IPXFRM          (1U<<21)    /**< Incomplete periodic
                                                 transfer mask.             */
#define GINTMSK_IISOOXFRM       (1U<<21)    /**< Incomplete isochronous OUT
                                                 transfer mask.             */
#define GINTMSK_IISOIXFRM       (1U<<20)    /**< Incomplete isochronous IN
                                                 transfer mask.             */
#define GINTMSK_OEPM            (1U<<19)    /**< OUT endpoints interrupt
                                                 mask.                      */
#define GINTMSK_IEPM            (1U<<18)    /**< IN endpoints interrupt
                                                 mask.                      */
#define GINTMSK_EPMISM          (1U<<17)    /**< Endpoint Mismatch interrupt
                                                 mask.                      */
#define GINTMSK_EOPFM           (1U<<15)    /**< End of periodic frame
                                                 interrupt mask.            */
#define GINTMSK_ISOODRPM        (1U<<14)    /**< Isochronous OUT packet
                                                 dropped interrupt mask.    */
#define GINTMSK_ENUMDNEM        (1U<<13)    /**< Enumeration done mask.     */
#define GINTMSK_USBRSTM         (1U<<12)    /**< USB reset mask.            */
#define GINTMSK_USBSUSPM        (1U<<11)    /**< USB suspend mask.          */
#define GINTMSK_ESUSPM          (1U<<10)    /**< Early suspend mask.        */
#define GINTMSK_GONAKEFFM       (1U<<7)     /**< Global OUT NAK effective
                                                 mask.                      */
#define GINTMSK_GINAKEFFM       (1U<<6)     /**< Global non-periodic IN NAK
                                                 effective mask.            */
#define GINTMSK_NPTXFEM         (1U<<5)     /**< Non-periodic TxFIFO empty
                                                 mask.                      */
#define GINTMSK_RXFLVLM         (1U<<4)     /**< Receive FIFO non-empty
                                                 mask.                      */
#define GINTMSK_SOFM            (1U<<3)     /**< Start of (micro)frame mask.*/
#define GINTMSK_OTGM            (1U<<2)     /**< OTG interrupt mask.        */
#define GINTMSK_MMISM           (1U<<1)     /**< Mode Mismatch interrupt
                                                 mask.                      */
/** @} */

/**
 * @name GRXSTSR register bit definitions
 * @{
 */
#define GRXSTSR_PKTSTS_MASK     (15U<<17)   /**< Packet status mask.        */
#define GRXSTSR_PKTSTS(n)       ((n##U)<<17)/**< Packet status value.       */
#define GRXSTSR_OUT_GLOBAL_NAK  GRXSTSR_PKTSTS(1)
#define GRXSTSR_OUT_DATA        GRXSTSR_PKTSTS(2)
#define GRXSTSR_OUT_COMP        GRXSTSR_PKTSTS(3)
#define GRXSTSR_SETUP_COMP      GRXSTSR_PKTSTS(4)
#define GRXSTSR_SETUP_DATA      GRXSTSR_PKTSTS(6)
#define GRXSTSR_DPID_MASK       (3U<<15)    /**< Data PID mask.             */
#define GRXSTSR_DPID(n)         ((n##U)<<15)/**< Data PID value.            */
#define GRXSTSR_BCNT_MASK       (0x7FF<<4)  /**< Byte count mask.           */
#define GRXSTSR_BCNT(n)         ((n##U)<<4) /**< Byte count value.          */
#define GRXSTSR_CHNUM_MASK      (15U<<0)    /**< Channel number mask.       */
#define GRXSTSR_CHNUM(n)        ((n##U)<<0) /**< Channel number value.      */
#define GRXSTSR_EPNUM_MASK      (15U<<0)    /**< Endpoint number mask.      */
#define GRXSTSR_EPNUM(n)        ((n##U)<<0) /**< Endpoint number value.     */
/** @} */

/**
 * @name GRXSTSP register bit definitions
 * @{
 */
#define GRXSTSP_PKTSTS_MASK     (15<<17)    /**< Packet status mask.        */
#define GRXSTSP_PKTSTS(n)       ((n##U)<<17)/**< Packet status value.       */
#define GRXSTSP_OUT_GLOBAL_NAK  GRXSTSP_PKTSTS(1)
#define GRXSTSP_OUT_DATA        GRXSTSP_PKTSTS(2)
#define GRXSTSP_OUT_COMP        GRXSTSP_PKTSTS(3)
#define GRXSTSP_SETUP_COMP      GRXSTSP_PKTSTS(4)
#define GRXSTSP_SETUP_DATA      GRXSTSP_PKTSTS(6)
#define GRXSTSP_DPID_MASK       (3U<<15)    /**< Data PID mask.             */
#define GRXSTSP_DPID(n)         ((n##U)<<15)/**< Data PID value.            */
#define GRXSTSP_BCNT_MASK       (0x7FF<<4)  /**< Byte count mask.           */
#define GRXSTSP_BCNT(n)         ((n##U)<<4) /**< Byte count value.          */
#define GRXSTSP_CHNUM_MASK      (15U<<0)    /**< Channel number mask.       */
#define GRXSTSP_CHNUM(n)        ((n##U)<<0) /**< Channel number value.      */
#define GRXSTSP_EPNUM_MASK      (15U<<0)    /**< Endpoint number mask.      */
#define GRXSTSP_EPNUM(n)        ((n##U)<<0) /**< Endpoint number value.     */
/** @} */

/**
 * @name GRXFSIZ register bit definitions
 * @{
 */
#define GRXFSIZ_RXFD_MASK       (0xFFFF<<0) /**< RxFIFO depth mask.         */
#define GRXFSIZ_RXFD(n)         ((n##U)<<0) /**< RxFIFO depth value.        */
/** @} */

/**
 * @name GNPTXFSIZ register bit definitions
 * @{
 */
#define GNPTXFSIZ_NPTXFD_MASK   (0xFFFFU<<16)/**< Non-periodic TxFIFO depth
                                                 mask.                      */
#define GNPTXFSIZ_NPTXFD(n)     ((n##U)<<16)/**< Non-periodic TxFIFO depth
                                                 value.                     */
#define GNPTXFSIZ_NPTXFSA_MASK  (0xFFFFU<<0)/**< Non-periodic transmit RAM
                                                 start address mask.        */
#define GNPTXFSIZ_NPTXFSA(n)    ((n##U)<<0) /**< Non-periodic transmit RAM
                                                 start address value.       */
/** @} */

/**
 * @name GNPTXSTS register bit definitions
 * @{
 */
#define GNPTXSTS_NPTxQTop_MASK      (0x7F<<24)  /**< Top of the non-periodic
                                                     transmit request queue
                                                     mask.                  */
#define GNPTXSTS_NPTxQTop(n)        ((n)<<24)   /**< Top of the non-periodic
                                                     transmit request queue
                                                     value.                 */
#define GNPTXSTS_NPTxQSpcAvail_MASK (0xFF<<16)  /**< non-periodic transmit
                                                     request queue Space
                                                     Available mask.        */
#define GNPTXSTS_NPTxQSpcAvail(n)   ((n)<<16)   /**< non-periodic transmit
                                                     request queue Space
                                                     Available value.       */
#define GNPTXSTS_NPTxFSpcAvail_MASK (0xFFFF<<0) /**< non-periodic TxFIFO
                                                     Space Available mask.  */
#define GNPTXSTS_NPTxFSpcAvail(n)   ((n)<<0)    /**< non-periodic TxFIFO
                                                     Space Available value. */
/** @} */

/**
 * @name HPTXFSIZ register bit definitions
 * @{
 */
#define HPTXFSIZ_PTxFsize_MASK      (0xFFFF<<16)/**< Host periodic TxFIFO
                                                     Depth mask.            */
#define HPTXFSIZ_PTxFsize(n)        ((n)<<16)   /**< Host periodic TxFIFO
                                                     Depth value.           */
#define HPTXFSIZ_PTxFStAddr_MASK    (0xFFFF<<0) /**< Host periodic TxFIFO
                                                     Start Address mask.    */
#define HPTXFSIZ_PTxFStAddr(n)      ((n)<<0)    /**< Host periodic TxFIFO
                                                     Start Address value.   */
/** @} */

/**
 * @name DPTXFSIZ register bit definitions
 * @{
 */
#define DPTXFSIZ_DPTxFsize_MASK     (0xFFFF<<16 /**< Device periodic TxFIFO
                                                     size mask.             */
#define DPTXFSIZ_DPTxFsize(n)       ((n)<<16)   /**< Device periodic TxFIFO
                                                     size value.            */
#define DPTXFSIZ_DPTxFStAddr_MASK   (0xFFFF<<0) /**< Device periodic TxFIFO
                                                     RAM Start Address mask.*/
#define DPTXFSIZ_DPTxFStAddr(n)     ((n)<<0)    /**< Device periodic TxFIFO
                                                     RAM Start Address
                                                     value.                 */
/** @} */

/**
 * @name HCFG register bit definitions
 * @{
 */
#define HCFG_ResValid_MASK          (0xFF<<8)   /**< Resume Validation
                                                     Period mask.           */
#define HCFG_ResValid(n)            ((n)<<8)    /**< Resume Validation
                                                     Period value.          */
#define HCFG_Ena32KHzS              (1U<<7)      /**< enable 32-KHz suspend
                                                     Mode.                  */
#define HCFG_FSLSSupp               (1U<<2)      /**< FS- and LS-Only
                                                     Support.               */
#define HCFG_FSLSPclkSel_MASK       (3<<0)      /**< FS/LS PHY clock Select
                                                     mask.                  */
#define HCFG_FSLSPclkSel_30_60      (0<<0)      /**< PHY clock is running at
                                                     30/60 MHz.             */
#define HCFG_FSLSPclkSel_48         (1U<<0)      /**< PHY clock is running at
                                                     48 MHz.                */
/** @} */

/**
 * @name HFIR register bit definitions
 * @{
 */
#define HFIR_FrInt_MASK             (0xFFFF<<0) /**< frame interval mask.   */
#define HFIR_FrInt(n)               ((n)<<0)    /**< frame interval value.  */
/** @} */

/**
 * @name HFNUM register bit definitions
 * @{
 */
#define HFNUM_FrRem_MASK            (0xFFFF<<16)/**< frame time Remaining
                                                     mask.                  */
#define HFNUM_FrRem(n)              ((n)<<16)   /**< frame time Remaining
                                                     value.                 */
#define HFNUM_FrNum_MASK            (0xFFFF<<0) /**< frame number mask.     */
#define HFNUM_FrNum(n)              ((n)<<0)    /**< frame number value.    */
/** @} */

/**
 * @name HPTXSTS register bit definitions
 * @{
 */
#define HPTXSTS_PTxQTop_MASK        (0xFF<<24)  /**< Top of the periodic
                                                     transmit request queue
                                                     mask.                  */
#define HPTXSTS_PTxQTop(n)          ((n)<<24)   /**< Top of the periodic
                                                     transmit request queue
                                                     value.                 */
#define HPTXSTS_PTxQSpcAvail_MASK   (0xFF<<16)  /**< periodic transmit request
                                                     queue Space Available
                                                     mask.                  */
#define HPTXSTS_PTxQSpcAvail(n)     ((n)<<16)   /**< periodic transmit request
                                                     queue Space Available
                                                     value.                 */
#define HPTXSTS_PTxFSpcAvail_MASK   (0xFFFF<<0) /**< periodic transmit Data
                                                     FIFO Space Available
                                                     mask.                  */
#define HPTXSTS_PTxFSpcAvail(n)     ((n)<<0)    /**< periodic transmit Data
                                                     FIFO Space Available
                                                     value.                 */
/** @} */

/**
 * @name HAINT register bit definitions
 * @{
 */
#define HAINT_HAINT_MASK            (0xFFFF<<0) /**< channel interrupts
                                                     mask.                  */
#define HAINT_HAINT(n)              ((n)<<0)    /**< channel interrupts
                                                     value.                 */
/** @} */

/**
 * @name HAINTMSK register bit definitions
 * @{
 */
#define HAINTMSK_HAINTMsk_MASK      (0xFFFF<<0) /**< channel interrupt mask
                                                     mask.                  */
#define HAINTMSK_HAINTMsk(n)        ((n)<<0)    /**< channel interrupt mask
                                                     value.                 */
/** @} */

/**
 * @name HPRT register bit definitions
 * @{
 */
#define HPRT_PrtSpd_MASK            (3<<17)     /**< port Speed mask.       */
#define HPRT_PrtSpd_HS              (0<<17)     /**< High Speed value.      */
#define HPRT_PrtSpd_FS              (1U<<17)     /**< Full Speed value.      */
#define HPRT_PrtSpd_LS              (2<<17)     /**< Low Speed value.       */
#define HPRT_PrtTstCtl_MASK         (15<<13)    /**< port Test control mask.*/
#define HPRT_PrtTstCtl(n)           ((n)<<13)   /**< port Test control
                                                     value.                 */
#define HPRT_PrtPwr                 (1U<<12)     /**< port power.            */
#define HPRT_PrtLnSts_MASK          (3<<11)     /**< port Line status mask. */
#define HPRT_PrtLnSts_DM            (1U<<11)     /**< Logic level of D-.     */
#define HPRT_PrtLnSts_DP            (1U<<10)     /**< Logic level of D+.     */
#define HPRT_PrtRst                 (1U<<8)      /**< port reset.            */
#define HPRT_PrtSusp                (1U<<7)      /**< port suspend.          */
#define HPRT_PrtRes                 (1U<<6)      /**< port Resume.           */
#define HPRT_PrtOvrCurrChng         (1U<<5)      /**< port Overcurrent
                                                     change.                */
#define HPRT_PrtOvrCurrAct          (1U<<4)      /**< port Overcurrent
                                                     Active.                */
#define HPRT_PrtEnChng              (1U<<3)      /**< port enable/Disable
                                                     change.                */
#define HPRT_PrtEna                 (1U<<2)      /**< port enable.           */
#define HPRT_PrtConnDet             (1U<<1)      /**< port Connect detected. */
#define HPRT_PrtConnSts             (1U<<0)      /**< .*/
/** @} */

/**
 * @name HCCHAR register bit definitions
 * @{
 */
#define HCCHAR_ChEna                (1u<<31)    /**< channel enable.        */
#define HCCHAR_ChDis                (1U<<30)     /**< channel Disable.       */
#define HCCHAR_OddFrm               (1U<<29)     /**< Odd frame.             */
#define HCCHAR_DevAddr_MASK         (0x7F<<22)  /**< Device Address mask.   */
#define HCCHAR_DevAddr(n)           ((n)<<22)   /**< Device Address value.  */
#define HCCHAR_MC_EC_MASK           (3<<20)     /**< Multi count (MC) / Error
                                                     count mask.            */
#define HCCHAR_MC_EC(n)             ((n)<<20)   /**< Multi count (MC) / Error
                                                     count value.           */
#define HCCHAR_EPType_MASK          (3<<18)         /**< .*/
#define HCCHAR_EPType(n)            ((n)<<18)   /**< endpoint Type mask.    */
#define HCCHAR_EPType_control       (0<<18)     /**< control endpoint value.*/
#define HCCHAR_EPType_isochronous   (1U<<18)     /**< isochronous endpoint
                                                     value.                 */
#define HCCHAR_EPType_Bulk          (2<<18)     /**< Bulk endpoint value.   */
#define HCCHAR_EPType_interrupt     (3<<18)     /**< interrupt endpoint
                                                     value.                 */
#define HCCHAR_LSpdDev              (1U<<17)     /**< Low-Speed Device.      */
#define HCCHAR_EPDir                (1U<<15)     /**< endpoint Direction.    */
#define HCCHAR_EPNum_MASK           (15<<11)    /**< endpoint number mask.  */
#define HCCHAR_EPNum(n)             ((n)<<11)   /**< endpoint number value. */
#define HCCHAR_MPS_MASK             (11<<0)     /**< Maximum Packet size
                                                     mask.                  */
#define HCCHAR_MPS(n)               (11<<0)     /**< Maximum Packet size
                                                     value.                 */
/** @} */

/**
 * @name HCSPLT register bit definitions
 * @{
 */
#define HCSPLT_SpltEna              (1u<<31)    /**< Split enable.          */
#define HCSPLT_CompSplt             (1U<<16)     /**< Do Complete Split.     */
#define HCSPLT_XactPos_MASK         (3<<14)     /**< Transaction Position.  */
#define HCSPLT_XactPos_Mid          (0<<14)     /**< Middle.                */
#define HCSPLT_XactPos_end          (1U<<14)     /**< End.                   */
#define HCSPLT_XactPos_Begin        (2<<14)     /**< Begin.                 */
#define HCSPLT_XactPos_all          (3<<14)     /**< All.                   */
#define HCSPLT_HubAddr_MASK         (0x7F<<6)   /**< Hub Address mask.      */
#define HCSPLT_HubAddr(n)           ((n)<<n)    /**< Hub Address value.     */
#define HCSPLT_PrtAddr_MASK         (0x7F<<0)   /**< port Address mask.     */
#define HCSPLT_PrtAddr(n)           ((n)<<0)    /**< port Address value.    */
/** @} */

/**
 * @name HCINT register bit definitions
 * @{
 */
#define HCINT_DataTglErr            (1U<<10)     /**< Data Toggle Error.     */
#define HCINT_FrmOvrun              (1U<<9)      /**< frame Overrun.         */
#define HCINT_BblErr                (1U<<8)      /**< Babble Error.          */
#define HCINT_XactErr               (1U<<7)      /**< Transaction Error.     */
#define HCINT_NYET                  (1U<<6)      /**< NYET Response Received
                                                     interrupt.             */
#define HCINT_ACK                   (1U<<5)      /**< ACK Response
                                                     Received/transmitted
                                                     interrupt.             */
#define HCINT_NAK                   (1U<<4)      /**< NAK Response Received
                                                     interrupt.             */
#define HCINT_STALL                 (1U<<3)      /**< STALL Response Received
                                                     interrupt.             */
#define HCINT_ChHltd                (1U<<1)      /**< channel Halted.        */
#define HCINT_XferCompl             (1U<<0)      /**< transfer completed.    */
/** @} */

/**
 * @name HCINTMSK register bit definitions
 * @{
 */
#define HCINTMSK_DataTglErrMsk      (1U<<10)     /**< Data Toggle Error mask.*/
#define HCINTMSK_FrmOvrunMsk        (1U<<9)      /**< frame Overrun mask.    */
#define HCINTMSK_BblErrMsk          (1U<<8)      /**< Babble Error mask.     */
#define HCINTMSK_XactErrMsk         (1U<<7)      /**< Transaction Error mask.*/
#define HCINTMSK_NyetMsk            (1U<<6)      /**< NYET Response Received
                                                     interrupt mask.        */
#define HCINTMSK_AckMsk             (1U<<5)      /**< ACK Response
                                                     Received/transmitted
                                                     interrupt mask.        */
#define HCINTMSK_NakMsk             (1U<<4)      /**< NAK Response Received
                                                     interrupt mask.        */
#define HCINTMSK_StallMsk           (1U<<3)      /**< STALL Response Received
                                                     interrupt mask.        */
#define HCINTMSK_ChHltdMsk          (1U<<1)      /**< channel Halted mask.   */
#define HCINTMSK_XferComplMsk       (1U<<0)      /**< transfer completed
                                                     mask.*/
/** @} */

/**
 * @name HCTSIZ register bit definitions
 * @{
 */
#define HCTSIZ_DoPng                (1U<<31)     /**< Do Ping.               */
#define HCTSIZ_Pid_MASK             (3<<29)     /**< PID mask.              */
#define HCTSIZ_Pid_DATA0            (0<<29)     /**< DATA0.                 */
#define HCTSIZ_Pid_DATA2            (1U<<29)     /**< DATA2.                 */
#define HCTSIZ_Pid_DATA1            (2<<29)     /**< DATA1.                 */
#define HCTSIZ_Pid_MDATA            (3<<29)     /**< MDATA.                 */
#define HCTSIZ_Xfersize_MASK        (0x7FFFF<<0)/**< transfer size mask.    */
#define HCTSIZ_Xfersize(n)          ((n)<<0)    /**< transfer size value.   */
/** @} */

/**
 * @name DCFG register bit definitions
 * @{
 */
#define DCFG_ResValid_MASK          (0x3F<<26)  /**< Resume Validation Period
                                                     mask.                  */
#define DCFG_ResValid(n)            ((n)<<26)   /**< Resume Validation Period
                                                     value.                 */
#define DCFG_EPMiscnt_MASK          (0x1F<<18)  /**< IN endpoint Mismatch
                                                     count mask.            */
#define DCFG_EPMiscnt(n)            ((n)<<18)   /**< IN endpoint Mismatch
                                                     count value.           */
#define DCFG_PerFrInt_MASK          (3<<11)     /**< periodic frame interval
                                                     mask.                  */
#define DCFG_PerFrInt(n)            ((n)<<11)   /**< periodic frame interval
                                                     value.                 */
#define DCFG_DevAddr_MASK           (0x7F<<4)   /**< Device Address mask.   */
#define DCFG_DevAddr(n)             ((n)<<4)    /**< Device Address value.  */
#define DCFG_Ena32KHzS              (1U<<3)      /**< enable 32-KHz suspend
                                                     Mode.                  */
#define DCFG_NZStsOUTHShk           (1U<<2)      /**< non-Zero-Length status
                                                     OUT Handshake.         */
#define DCFG_DevSpd_MASK            (3<<0)      /**< Device Speed mask.     */
#define DCFG_DevSpd_HS20            (0<<0)      /**< High speed (USB 2.0 PHY
                                                     clock is 30 MHz or 60
                                                     MHz).                  */
#define DCFG_DevSpd_FS20            (1U<<0)      /**< Full speed (USB 2.0 PHY
                                                     clock is 30 MHz or 60
                                                     MHz).                  */
#define DCFG_DevSpd_Reserved        (2<<0)      /**< Reserved.              */
#define DCFG_DevSpd_FS11            (3<<0)      /**< Full speed (USB 1.1
                                                     transceiver clock is 48
                                                     MHz).                  */
/** @} */

/**
 * @name DCTL register bit definitions
 * @{
 */
#define DCTL_NakOnBble              (1U<<16)     /**< Set NAK automatically on
                                                     babble.                */
#define DCTL_PWROnPrgdone           (1U<<11)     /**< power-On Programming
                                                     done.                  */
#define DCTL_CGOUTNak               (1U<<10)     /**< Clear Global OUT NAK.  */
#define DCTL_SGOUTNak               (1U<<9)      /**< Set Global OUT NAK.    */
#define DCTL_CGNPInNak              (1U<<8)      /**< Clear Global non-periodic
                                                     IN NAK.                */
#define DCTL_SGNPInNak              (1U<<7)      /**< Set Global non-periodic
                                                     IN NAK.                */
#define DCTL_TstCtl_MASK            (7<<4)      /**< Test control mask.     */
#define DCTL_TstCtl(n)              ((n)<<4)    /**< Test control value.    */
#define DCTL_GOUTNakSts             (1U<<3)      /**< Global OUT NAK status. */
#define DCTL_GNPINNakSts            (1U<<2)      /**< Global non-periodic IN
                                                     NAK status.            */
#define DCTL_SftDiscon              (1U<<1)      /**< Soft disconnect.       */
#define DCTL_RmtWkUpSig             (1U<<0)      /**< Remote wakeup
                                                     signaling.             */
/** @} */

/**
 * @name DSTS register bit definitions
 * @{
 */
#define DSTS_SOFFN_MASK             (0x3FFF<<8) /**< frame or Microframe
                                                     number of the Received
                                                     SOF mask.              */
#define DSTS_SOFFN(n)               ((n)<<8)    /**< frame or Microframe
                                                     number of the Received
                                                     SOF value.             */
#define DSTS_ErrticErr              (1U<<3)      /**< Erratic Error.         */
#define DSTS_EnumSpd_MASK           (3<<1)      /**< Enumerated Speed mask. */
#define DSTS_EnumSpd_HS_30_60       (0<<1)      /**< High speed (PHY clock is
                                                     running at 30 or 60
                                                     MHz).                  */
#define DSTS_EnumSpd_FS_30_60       (1U<<1)      /**< Full speed (PHY clock is
                                                     running at 30 or 60
                                                     MHz).                  */
#define DSTS_EnumSpd_LS_48_6        (2<<1)      /**< Low speed (PHY clock is
                                                     running at 48 MHz,
                                                     internal phy_clk at 6
                                                     MHz).                  */
#define DSTS_EnumSpd_FS_48          (3<<1)      /**< Full speed (PHY clock is
                                                     running at 48 MHz).    */
#define DSTS_SuspSts                (1U<<0)      /**< suspend status.        */
/** @} */

/**
 * @name DIEPMSK register bit definitions
 * @{
 */
#define DIEPMSK_NAKMsk              (1U<<13)     /**< NAK interrupt mask.    */
#define DIEPMSK_BNAInIntrMsk        (1U<<9)      /**< BNA interrupt mask.    */
#define DIEPMSK_TxfifoUndrnMsk      (1U<<8)      /**< Fifo Underrun mask.    */
#define DIEPMSK_INEPNakEffMsk       (1U<<6)      /**< IN endpoint NAK Effective
                                                     mask.                  */
#define DIEPMSK_INTknEPMisMsk       (1U<<5)      /**< IN Token received with
                                                     EP Mismatch mask.      */
#define DIEPMSK_INTknTXFEmpMsk      (1U<<4)      /**< IN Token Received When
                                                     TxFIFO empty mask.     */
#define DIEPMSK_timeOUTMsk          (1U<<3)      /**< timeout condition mask.*/
#define DIEPMSK_AHBErrMsk           (1U<<2)      /**< AHB Error mask.        */
#define DIEPMSK_EPDisbldMsk         (1U<<1)      /**< endpoint disabled
                                                     interrupt mask.        */
#define DIEPMSK_XferComplMsk        (1U<<0)      /**< transfer completed
                                                     interrupt mask.        */
/** @} */

/**
 * @name DOEPMSK register bit definitions
 * @{
 */
#define DOEPMSK_NYETMsk             (1U<<14)     /**< NYET interrupt mask.   */
#define DOEPMSK_NAKMsk              (1U<<13)     /**< NAK interrupt mask.    */
#define DOEPMSK_BbleErrMsk          (1U<<12)     /**< Babble interrupt mask. */
#define DOEPMSK_BnaOutIntrMsk       (1U<<9)      /**< BNA interrupt mask.    */
#define DOEPMSK_OutPktErrMsk        (1U<<8)      /**< OUT Packet Error mask. */
#define DOEPMSK_Back2BackSETup      (1U<<6)      /**< Back-to-Back SETUP
                                                     Packets Received mask. */
#define DOEPMSK_OUTTknEPdisMsk      (1U<<4)      /**< OUT Token Received when
                                                     endpoint disabled mask.*/
#define DOEPMSK_SetUPMsk            (1U<<3)      /**< SETUP phase done mask. */
#define DOEPMSK_AHBErrMsk           (1U<<2)      /**< AHB Error.             */
#define DOEPMSK_EPDisbldMsk         (1U<<1)      /**< endpoint disabled
                                                     interrupt mask.        */
#define DOEPMSK_XferComplMsk        (1U<<0)      /**< transfer completed
                                                     interrupt mask.        */
/** @} */

/**
 * @name DAINT register bit definitions
 * @{
 */
#define DAINT_OutEPInt_MASK         (0xFFFF<<16)/**< OUT endpoint interrupt
                                                     Bits mask.             */
#define DAINT_OutEPInt(n)           ((n)<<16)   /**< OUT endpoint interrupt
                                                     Bits value.            */
#define DAINT_InEpInt_MASK          (0xFFFF<<0) /**< IN endpoint interrupt
                                                     Bits mask.             */
#define DAINT_InEpInt(n)            ((n)<<0)    /**< IN endpoint interrupt
                                                     Bits value.            */
/** @} */

/**
 * @name DAINTMSK register bit definitions
 * @{
 */
#define DAINTMSK_OutEpMsk_MASK      (0xFFFF<<16)/**< OUT EP interrupt mask
                                                     Bits mask.             */
#define DAINTMSK_OutEpMsk(n)        (1U<<(16+(n)))/**< OUT EP interrupt mask
                                                     Bits value.            */
#define DAINTMSK_InEpMsk_MASK       (0xFFFF<<0) /**< IN EP interrupt mask
                                                     Bits mask.             */
#define DAINTMSK_InEpMsk(n)         (1U<<(n))    /**< IN EP interrupt mask
                                                     Bits value.            */
/** @} */

/**
 * @name DVBUSDIS register bit definitions
 * @{
 */
#define DVBUSDIS_DVBUSDis_MASK      (0xFFFF<<0) /**< Device VBUS Discharge
                                                     time mask.             */
#define DVBUSDIS_DVBUSDis(n)        ((n)<<0)    /**< Device VBUS Discharge
                                                     time value.            */
/** @} */

/**
 * @name DVBUSPULSE register bit definitions
 * @{
 */
#define DVBUSPULSE_DVBUSPulse_MASK  (0xFFF<<0)  /**< Device VBUS Pulsing time
                                                     mask.                  */
#define DVBUSPULSE_DVBUSPulse(n)    ((n)<<0)    /**< Device VBUS Pulsing time
                                                     value.                 */
/** @} */

/**
 * @name DIEPCTL register bit definitions
 * @{
 */
#define DIEPCTL_EPEna               (1u<<31)    /**< endpoint enable.       */
#define DIEPCTL_EPDis               (1U<<30)     /**< endpoint Disable.      */
#define DIEPCTL_SetD1PID            (1U<<29)     /**< Set DATA1 PID.         */
#define DIEPCTL_SetD0PID            (1U<<28)     /**< Set DATA0 PID.         */
#define DIEPCTL_SNAK                (1U<<27)     /**< Set NAK.               */
#define DIEPCTL_CNAK                (1U<<26)     /**< Clear NAK.             */
#define DIEPCTL_TxFNum_MASK         (15<<22)    /**< TxFIFO number mask.    */
#define DIEPCTL_TxFNum(n)           ((n)<<22)   /**< TxFIFO number value.   */
#define DIEPCTL_Stall               (1U<<21)     /**< STALL Handshake.       */
#define DIEPCTL_Snp                 (1U<<20)     /**< Snoop Mode.            */
#define DIEPCTL_EPType_MASK         (3<<18)     /**< endpoint Type mask.    */
#define DIEPCTL_EPType_control      (0<<18)     /**< control.               */
#define DIEPCTL_EPType_isochronous  (1U<<18)     /**< isochronous.           */
#define DIEPCTL_EPType_Bulk         (2<<18)     /**< Bulk.                  */
#define DIEPCTL_EPType_interrupt    (3<<18)     /**< interrupt.             */
#define DIEPCTL_NAKSts              (1U<<17)     /**< NAK status.            */
#define DIEPCTL_DPID                (1U<<16)     /**< endpoint Data PID.     */
#define DIEPCTL_USBActEP            (1U<<15)     /**< USB Active endpoint.   */
#define DIEPCTL_NextEp_MASK         (15<<11)    /**< Next endpoint mask.    */
#define DIEPCTL_NextEp(n)           ((n)<<11)   /**< Next endpoint value.   */
#define DIEPCTL_MPS_MASK            (0x3FF<<0)  /**< Maximum Packet size
                                                     mask.                  */
#define DIEPCTL_MPS(n)              ((n)<<0)    /**< Maximum Packet size
                                                     value.                 */
/** @} */

/**
 * @name DIEPINT register bit definitions
 * @{
 */
#define DIEPINT_NYETIntrpt          (1U<<14)     /**< NYET interrupt.        */
#define DIEPINT_NAKIntrpt           (1U<<13)     /**< NAK interrupt.         */
#define DIEPINT_BbleErrIntrpt       (1U<<12)     /**< BbleErr (Babble Error)
                                                     interrupt.             */
#define DIEPINT_TxFEmp              (1U<<7)      /**< transmit FIFO empty.   */
#define DIEPINT_INEPNakEff          (1U<<6)      /**< IN endpoint NAK
                                                     Effective.             */
#define DIEPINT_INTknEPMis          (1U<<5)      /**< IN Token Received with
                                                     EP Mismatch.           */
#define DIEPINT_INTknTXFEmp         (1U<<4)      /**< IN Token Received When
                                                     TxFIFO is empty.       */
#define DIEPINT_timeOUT             (1U<<3)      /**< timeout condition.     */
#define DIEPINT_AHBErr              (1U<<2)      /**< AHB Error.             */
#define DIEPINT_EPDisbld            (1U<<1)      /**< endpoint disabled
                                                     interrupt.             */
#define DIEPINT_XferCompl           (1U<<0)      /**< transfer completed     */
/** @} */

/**
 * @name DIEPTSIZ register bit definitions
 * @{
 */
#define DIEPTSIZ_MC_MASK            (3<<29)     /**< Multi count mask.      */
#define DIEPTSIZ_MC(n)              ((n)<<29)   /**< Multi count value.     */
#define DIEPTSIZ_Pktcnt_MASK        (0x3FF<<19) /**< Packet count mask.     */
#define DIEPTSIZ_Pktcnt(n)          ((n)<<19)   /**< Packet count value.    */
#define DIEPTSIZ_Xfersize_MASK      (0x7FFFF<<0)/**< transfer size mask.    */
#define DIEPTSIZ_Xfersize(n)        ((n)<<0)    /**< transfer size value.   */
/** @} */

/**
 * @name DOEPCTL register bit definitions.
 * @{
 */
#define DOEPCTL_EPEna               (1u<<31)    /**< endpoint enable.       */
#define DOEPCTL_EPDis               (1U<<30)     /**< endpoint Disable.      */
#define DOEPCTL_SetOddFr            (1U<<29)     /**< Set Odd (micro)frame.  */
#define DOEPCTL_SetEvenFr           (1U<<28)     /**< Set Even (micro)frame. */
#define DOEPCTL_SNAK                (1U<<27)     /**< Set NAK.               */
#define DOEPCTL_CNAK                (1U<<26)     /**< Clear NAK.             */
#define DOEPCTL_Stall               (1U<<21)     /**< STALL Handshake.       */
#define DOEPCTL_Snp                 (1U<<20)     /**< Snoop Mode.            */
#define DOEPCTL_EPType_MASK         (3<<18)     /**< endpoint Type mask.    */
#define DOEPCTL_EPType_control      (0<<18)     /**< control.               */
#define DOEPCTL_EPType_isochronous  (1U<<18)     /**< Isochronous.           */
#define DOEPCTL_EPType_Bulk         (2<<18)     /**< Bulk.                  */
#define DOEPCTL_EPType_interrupt    (3<<18)     /**< interrupt.             */
#define DOEPCTL_NAKSts              (1U<<17)     /**< NAK status.            */
#define DOEPCTL_EO_FrNum            (1U<<16)     /**< Even/Odd (Micro)frame. */
#define DOEPCTL_USBActEP            (1U<<15)     /**< USB Active endpoint.   */
#define DOEPCTL_NextEp_MASK         (15<<11)    /**< Next endpoint mask.    */
#define DOEPCTL_NextEp(n)           ((n)<<11)   /**< Next endpoint value.   */
#define DOEPCTL_MPS_MASK            (0x3FF<<0)  /**< Maximum Packet size
                                                     mask.                  */
#define DOEPCTL_MPS(n)              ((n)<<0)    /**< Maximum Packet size
                                                     value.                 */
/** @} */

/**
 * @name DOEPINT register bit definitions
 * @{
 */
#define DOEPINT_NYETIntrpt          (1U<<14)     /**< NYET interrupt.        */
#define DOEPINT_NAKIntrpt           (1U<<13)     /**< NAK interrupt.         */
#define DOEPINT_BbleErrIntrpt       (1U<<12)     /**< BbleErr (Babble Error)
                                                     interrupt.             */
#define DOEPINT_Back2BackSETup      (1U<<6)      /**< Back-to-Back SETUP
                                                     Packets Received.      */
#define DOEPINT_OUTTknEPdis         (1U<<4)      /**< OUT Token Received When
                                                     endpoint disabled.     */
#define DOEPINT_SetUp               (1U<<3)      /**< SETUP phase done.      */
#define DOEPINT_AHBErr              (1U<<2)      /**< AHB Error.             */
#define DOEPINT_EPDisbld            (1U<<1)      /**< endpoint disabled
                                                     interrupt.             */
#define DOEPINT_XferCompl           (1U<<0)      /**< transfer completed
                                                     interrupt.             */
/** @} */

/**
 * @name DOEPTSIZ register bit definitions
 * @{
 */
#define DOEPTSIZ_SUPcnt_MASK        (3<<29)     /**< SETUP Packet cnt mask. */
#define DOEPTSIZ_SUPcnt(n)          ((n)<<29)   /**< SETUP Packet cnt value.*/
#define DOEPTSIZ_Pktcnt_MASK        (0x3FF<<19) /**< Packet count mask.     */
#define DOEPTSIZ_Pktcnt(n)          ((n)<<19)   /**< Packet count value.    */
#define DOEPTSIZ_Xfersize_MASK      (0x7FFFF<<0)/**< transfer size mask.    */
#define DOEPTSIZ_Xfersize(n)        ((n)<<0)    /**< transfer size value.   */
/** @} */

/**
 * @name PCGCCTL register bit definitions
 * @{
 */
#define PCGCCTL_resetafterSusp      (1U<<8)      /**< reset after suspend.   */
#define PCGCCTL_L1suspended         (1U<<7)      /**< Deep sleep.            */
#define PCGCCTL_Physleep            (1U<<6)      /**< PHY in sleep.          */
#define PCGCCTL_Enbl_L1gating       (1U<<5)      /**< enable sleep clock
                                                     gating.                */
#define PCGCCTL_RstPdwnModule       (1U<<3)      /**< reset power-down
                                                     modules.               */
#define PCGCCTL_PwrClmp             (1U<<2)      /**< Power clamp.           */
#define PCGCCTL_GateHclk            (1U<<1)      /**< Gate Hclk.             */
#define PCGCCTL_StopPclk            (1U<<0)      /**< Stop Pclk.             */
/** @} */

/**
 * @brief   OTG registers block memory address.
 */
#define OTG_ADDR                    0x50000000

/**
 * @brief   Accesses to the OTG registers block.
 */
#define OTG                         ((stm32_otg_t *)OTG_ADDR)

/**
 * @brief   Returns a FIFO address.
 */
#define OTG_FIFO(n)                 ((volatile uint32_t *)(OTG_ADDR +       \
                                                           0x1000 +
                                                           (0x1000 * (n))))

#endif /* _STM32_OTG_H_ */

/** @} */