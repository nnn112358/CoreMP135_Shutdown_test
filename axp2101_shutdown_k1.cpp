
// Copyright (c) 2024 @nnn112358<https://github.com/nnn112358/>
//$ arm-linux-gnueabihf-g++ coremp135_i2c_backlight_ctrl.cpp -o
//  coremp135_i2c_backlight_ctrl

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#include <bitset>
#include <iostream>

// Define constants for I2C communication
#define AXP2101_ADDR 0x34
#define AXP2101_Shutdown 0x10

void print_binary(uint8_t value) {
    printf("Binary: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
    printf("\n");
}


void write1Byte(int i2c_fd, uint8_t reg, uint8_t value) {
    uint8_t buffer[2];
    buffer[0] = reg;
    buffer[1] = value;

    if (write(i2c_fd, buffer, 2) != 2) {
        perror("Failed to write to the i2c bus");
        exit(1);
    }
}

uint8_t read8Bit(int i2c_fd, uint8_t reg) {
    if (write(i2c_fd, &reg, 1) != 1) {
        perror("Failed to write to the i2c bus");
        exit(1);
    }

    uint8_t value;
    if (read(i2c_fd, &value, 1) != 1) {
        perror("Failed to read from the i2c bus");
        exit(1);
    }

    return value;
}


int main() {
    const char *dev = "/dev/i2c-0"; // 使用するI2Cバスを指定
    int addr = 0x34; // I2Cデバイスのアドレス

    int i2c_fd = open(dev, O_RDWR);
    if (i2c_fd < 0) {
        perror("Failed to open the i2c bus");
        exit(1);
    }

    if (ioctl(i2c_fd, I2C_SLAVE, addr) < 0) {
        perror("Failed to acquire bus access and/or talk to slave");
        exit(1);
    }

    uint8_t reg = 0x10;
    uint8_t value = read8Bit(i2c_fd, reg);
    printf("Hexadecimal: %02x\n", value);
    print_binary(value);
    printf("\n");
    value |= 0x01; // 1ビット目をセット
    
    uint8_t value_temp;
   printf("Enter the value to write : ");
    scanf("%hhx", &value_temp);
    
    write1Byte(i2c_fd, reg, value);

    close(i2c_fd);

    return 0;
}