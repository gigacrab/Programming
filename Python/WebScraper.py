from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
import base64
import time
import os

imgCount = 50
dirName = "unripe-apple-single"

query = "unripe single apple"
cService = webdriver.ChromeService(executable_path='/usr/bin/chromedriver')
chrome_executable_path = '/usr/bin/chromium'
chrome_options = Options()
chrome_options.binary_location = chrome_executable_path
driver = webdriver.Chrome(service=cService, options=chrome_options)
driver.maximize_window()
driver.get('https://images.google.com/')
box = driver.find_element(By.NAME, "q")
box.send_keys(query)
box.send_keys(Keys.ENTER)

def scroll_to_bottom():

    last_height = driver.execute_script('\
    return document.body.scrollHeight')

    while True:
        driver.execute_script('\
        window.scrollTo(0,document.body.scrollHeight)')

        # waiting for the results to load
        # Increase the sleep time if your internet is slow
        time.sleep(3)

        new_height = driver.execute_script('\
        return document.body.scrollHeight')

        # click on "Show more results" (if exists)
        try:
            driver.find_element_by_css_selector(".YstHxe input").click()

            # waiting for the results to load
            # Increase the sleep time if your internet is slow
            time.sleep(3)

        except:
            pass

        # checking if we have reached the bottom of the page
        if new_height == last_height:
            break

        last_height = new_height

scroll_to_bottom()

if not os.path.exists(dirName):
    os.makedirs(dirName)

imgArr = driver.find_elements(By.CLASS_NAME, 'YQ4gaf')
for i, img in enumerate(imgArr):
    if i > imgCount: break
    imgSrc = img.get_attribute("src")
    # Remove the prefix if it exists
    if imgSrc.startswith('data:image/jpeg;base64,'):
        imgSrc = imgSrc[len('data:image/jpeg;base64,'):]
    print(imgSrc)
    if imgSrc:
        try:
            imgData = base64.b64decode(imgSrc)
            imgName = f"{dirName}/img-{i}.jpeg"
            with open(imgName, "wb") as f:
                f.write(imgData)
            #print(f"{imgName} succeesfully written! {imgSrc} \n {imgData}")
        except Exception as e:
            print(f"Cant write!!!!: error {e}")
        

# Finally, we close the driver
driver.close()
