import pyautogui
import time
import io
import pyperclip




time.sleep(5)
f = open("buocquanhau.txt",'r', encoding = 'utf8')
g = open("cochangtraivietlencay.txt",'r', encoding = 'utf8')
list = ["buocquanhau.txt", "cochangtraivietlencay.txt", "matnaichacha.txt", "muonroimasaocon.txt"]
#text = f.readlines()
for file in list:
	f = open(file, 'r', encoding = 'utf8')
	for text in f:
		pyperclip.copy(text)
		pyautogui.hotkey("ctrl", "v")
		pyautogui.write("\n")
		time.sleep(2)

