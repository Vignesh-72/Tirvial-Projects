import webbrowser
import os
import time

def call(sec,link):
    time.sleep(1)
    for i in range(1,10,1):
        webbrowser.open(link)   
    time.sleep(11)
    os.system("taskkill /im chrome.exe /f")
    
target = input("Enter Link : ")
times = int(input("How Many Times Do You Like To Do This : "))
intervalTime = int(input("Enter Hold Time In Seconds : "))

for i in range(1,times,1):
    call(intervalTime,target)
//no need for pip
