# GIoT-Workshop-NDHU
# [1.1]
使用 mosquitto_sub.exe 驗證數據是否有發送至後端範例:
1.安裝 mosquitto 套件
2.於命令視窗鍵入下列指令(範例)接收數據
mosquitto_sub.exe -h 52.193.146.103 -p 80 -t client/200000166/200000166-GIOT-MAKER -I 200000166-generic-service -u 200000166 -P 80698426