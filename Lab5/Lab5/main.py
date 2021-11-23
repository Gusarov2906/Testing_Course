from time import sleep
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service as ChromeService
from selenium.webdriver.firefox.service import Service as FirefoxService
from selenium.webdriver.edge.service import Service as EdgeService

import passwords
import unittest
import warnings

browsers = ["../msedgedriver.exe", "../chromedriver.exe", "../geckodriver.exe"]


def get_driver(browser):
    if browser == "../msedgedriver.exe":
        s = EdgeService(browser)
        return webdriver.Edge(service=s)
    elif browser == "../chromedriver.exe":
        s = ChromeService(browser)
        return webdriver.Chrome(service=s)
    elif browser == "../geckodriver.exe":
        s = FirefoxService(browser)
        return webdriver.Firefox(service=s)


class BrowserTest(unittest.TestCase):
    def test_search_in_python_org(self):
        for browser in browsers:
            self.driver = get_driver(browser)
            self.driver.get("http://www.python.org")
            self.assertIn("Python", self.driver.title)
            elem = self.driver.find_element(By.NAME, "q")
            elem.send_keys("dfdsfdsfs")
            elem = self.driver.find_element(By.NAME, "submit")
            elem.click()
            sleep(0.25)
            assert "No results found." in self.driver.page_source
            sleep(0.5)
            self.driver.close()

    def test_search_in_duckduckgo_github_profile(self):
        for browser in browsers:
            self.driver = get_driver(browser)
            self.driver.get("http://www.duckduckgo.com")
            self.assertIn("DuckDuckGo — Максимум конфиденциальности, минимум усилий.", self.driver.title)
            elem = self.driver.find_element(By.ID, "search_form_input_homepage")
            elem.send_keys("gusarov2906")
            elem = self.driver.find_element(By.ID, "search_button_homepage")
            elem.click()
            sleep(0.25)
            elem = self.driver.find_element(By.CSS_SELECTOR, "a[href = 'https://github.com/Gusarov2906']")
            elem.click()
            sleep(0.25)
            elem = self.driver.find_element(By.XPATH, "//span[@itemprop='name']")
            assert "Andrew" in elem.text
            sleep(0.5)
            self.driver.close()

    def test_successful_login_myphotoshow_repl_co(self):
        for browser in browsers:
            self.driver = get_driver(browser)
            log_and_pas = passwords.LoginsAndPasswords
            self.driver.get("https://myphotoshow.gusarov2906.repl.co/")
            self.assertIn("MyPhotoShow", self.driver.title)
            elem = self.driver.find_element(By.XPATH, "//nav/a[1]")
            elem.click()
            sleep(0.25)
            elem = self.driver.find_element(By.NAME, "login")
            elem.send_keys(str(log_and_pas.password))
            elem = self.driver.find_element(By.NAME, "password")
            elem.send_keys(str(log_and_pas.login))
            elem = self.driver.find_element(By.XPATH, "//button")
            elem.click()
            sleep(0.25)
            elem = self.driver.find_element(By.CLASS_NAME, "profile_name")
            assert "@andrey29" in elem.text
            sleep(0.5)
            self.driver.close()

    def test_unsuccessful_login_myphotoshow_repl_co(self):
        for browser in browsers:
            self.driver = get_driver(browser)
            self.driver.get("https://myphotoshow.gusarov2906.repl.co/")
            self.assertIn("MyPhotoShow", self.driver.title)
            elem = self.driver.find_element(By.XPATH, "//nav/a[1]")
            elem.click()
            sleep(0.25)
            elem = self.driver.find_element(By.NAME, "login")
            elem.send_keys("aaa")
            elem = self.driver.find_element(By.NAME, "password")
            elem.send_keys("bbb")
            elem = self.driver.find_element(By.XPATH, "//button")
            url = self.driver.current_url
            elem.click()
            sleep(0.25)
            assert url == self.driver.current_url
            self.driver.close()

    def test_survey(self):
        for browser in browsers:
            self.driver = get_driver(browser)
            self.driver.get("https://pollservice.ru/p/5q3mc4w11s")
            self.assertIn("Интернет - польза или вред?. Опрос. Сервис интернет опросов - pollservice.ru",
                          self.driver.title)
            elem = self.driver.find_element(By.NAME, "pollservice_poll_0_answer")
            elem.click()
            sleep(0.25)
            elem = self.driver.find_element(By.CSS_SELECTOR,
                                            "div[class='pollservice-ru_button-answer pollservice-ru_btn-first ps-button ']")
            elem.click()
            sleep(0.25)
            assert "Дата создания опроса" in self.driver.page_source
            sleep(0.5)
            self.driver.close()


if __name__ == '__main__':
    warnings.filterwarnings("ignore", category=ResourceWarning)
    unittest.main(warnings='ignore')
