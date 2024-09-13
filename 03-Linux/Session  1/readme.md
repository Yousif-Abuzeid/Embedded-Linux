# Linux 

## Introduction

Linux is a family of open-source Unix-like operating systems based on the Linux kernel, an operating system kernel first released on September 17, 1991, by Linus Torvalds. Linux is typically packaged in a Linux distribution.

## History

Linux was originally developed for personal computers based on the Intel x86 architecture, but has since been ported to more platforms than any other operating system. Linux is the leading operating system on servers and other big iron systems such as mainframe computers, and the only OS used on TOP500 supercomputers (since November 2017, having gradually eliminated all competitors).

## Kernel

The development of Linux is one of the most prominent examples of free and open-source software collaboration. The underlying source code may be used, modified and distributed—commercially or non-commercially—by anyone under the terms of its respective licenses, such as the GNU General Public License.

## Distribution

Typically, Linux is packaged in a form known as a Linux distribution for desktop and server use. Some popular mainstream Linux distributions include Debian (and its derivatives such as Ubuntu), Fedora and openSUSE. Linux distributions include the Linux kernel, supporting utilities and libraries and usually a large amount of application software to fulfill the distribution's intended use.

## Conclusion

Linux is a leading operating system on servers and other big iron systems such as mainframe computers, and the only OS used on TOP500 supercomputers. It is used by around 2.3 percent of desktop computers. The Chromebook, which runs the Linux kernel-based Chrome OS, dominates the US K–12 education market and represents nearly 20 percent of sub-$300 notebook sales in the US.

## Boot Process

1. Press the power button on your computer.

2. The BIOS/UEFI boots up.
3. The BIOS/UEFI performs the power-on self-test (POST).
        
        - The POST checks the hardware to ensure that everything is working properly.
4. if the POST is successful, the BIOS/UEFI looks for the bootloader.

        - The bootloader is a small program that loads the operating system.
        - On BIOS System The Bootloader is stored on the Master Boot Record (MBR) or GUID Partition Table (GPT) of the hard drive.
        - On UEFI System The Bootloader is stored on the EFI System Partition (ESP).
5. The bootloader loads the kernel of the operating system into the computer's memory.
6. Start running the kernel code.

        - Common bootloaders are GRUB, LILO, SYSLINUX, and Gummiboot.
7. The Kernel takes over the computer resources.
8. The Kernel Checks Hardware and loads Device Drivers and other kernel modules.
9. The kernel starts the init process.

        - The init process is the first process started by the kernel.
        - The init process is responsible for starting all other processes on the system.

        ### Types of init systems

        - SysVinit
                : The traditional init system used in Linux distributions.

        - Systemd
                : A modern init system that is becoming the standard in many Linux distributions.


