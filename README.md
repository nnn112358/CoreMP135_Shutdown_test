## Abst
This is a test to turn off the power on AXP2101.
Be sure to run this while writing data to the MicroSD card or accessing the device

## cmd

```
$ arm-linux-gnueabihf-g++ axp2101_shutdown.cpp -o axp2101_shutdown
```


![image](https://github.com/nnn112358/CoreMP135_Shutdown_test/assets/27625496/02b27e58-9f8c-41ee-9db8-6d9a6430ab2a)


Reference:<br>
https://github.com/m5stack/M5Unified/blob/master/src/utility/AXP2101_Class.cpp <br>
https://github.com/m5stack/M5Core2/blob/master/src/AXP2101.cpp <br>
https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/docs/products/core/Core2%20v1.1/axp2101.pdf <br>
