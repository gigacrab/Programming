from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
import requests
import base64
import time
import os
import re

def scrollToBottom():
    lastHeight = driver.execute_script('\
    return document.body.scrollHeight')
    while True:
        driver.execute_script('\
        window.scrollTo(0,document.body.scrollHeight)')
        time.sleep(3)
        newHeight = driver.execute_script('\
        return document.body.scrollHeight')
        #press the get more images button if its there
        try:
            driver.find_element(By.CSS_SELECTOR, ".YstHxe input").click()
            time.sleep(3)
        except:
            pass
        if newHeight == lastHeight:
            break
        lastHeight = newHeight

#query = input("Query(What do you want to search for?): ")
#dirName = input("Directory Name/Path: ")
#imgCount = int(input("How many images?: "))
query = "unripe single banana"
dirName = "unripe-banana-single"
imgCount = 40

cService = webdriver.ChromeService(executable_path='/usr/bin/chromedriver')
chromeExecutablePath = '/usr/bin/chromium'
chromeOptions = Options()
chromeOptions.binary_location = chromeExecutablePath
driver = webdriver.Chrome(service=cService, options=chromeOptions)
driver.maximize_window()
driver.get('https://images.google.com/')
box = driver.find_element(By.NAME, "q")
box.send_keys(query)
box.send_keys(Keys.ENTER)

scrollToBottom()

if not os.path.exists(dirName):
    os.makedirs(dirName)

i = 0
imgIndex = 1
imgArr = driver.find_elements(By.CLASS_NAME, 'YQ4gaf')
print(f"Found {len(imgArr)} elements!")
while imgIndex <= imgCount:
    imgSrc = imgArr[i+5].get_attribute("src")
    if imgSrc:
        try:
            if imgSrc.startswith("https://encrypted-tbn0.gstatic.com/"):
                imgData = requests.get(imgSrc).content
            else: 
                srcSeg = re.split(":|;|,", imgSrc)
                ext = srcSeg[1].split('/')[1]
                if not ext == "jpeg": 
                    i += 1
                    continue
                imgData = base64.b64decode(srcSeg[3])
            imgName = f"{dirName}/img-{imgIndex}.jpeg"
            with open(imgName, "wb") as f:
                f.write(imgData)
            print(f"{imgName} succeesfully written!")
            imgIndex += 1
        except Exception as e:
            print(f"Cant write!!!!: error {e} {imgSrc}")
    i += 1

driver.close()
