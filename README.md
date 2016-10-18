# GIoT-Workshop-NDHU
# [1.1]
使用 mosquitto_sub.exe 驗證數據是否有發送至後端:<br>
1.下載並安裝 mosquitto 套件<br>
2.將 mosquitto.zip 裡的 DLL 檔複製到 mosquitto 的安裝路徑下<br>
3.於命令視窗執行 mosquitto_sub.exe 接收模組發送之數據 (以下為參考範例，請改用自己的mqtt帳號資訊帶入)<br>
mosquitto_sub.exe -h 52.193.146.103 -p 80 -t client/200000166/200000166-GIOT-MAKER -I 200000166-generic-service -u 200000166 -P 80698426
