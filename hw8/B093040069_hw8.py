#coding: utf-8 
import Tkinter as tk #pip3 install TK interface
from Tkinter import Scale
import os

n=0
f = [0]*100 	#使用者想碼掉的臉
window = tk.Tk() #build gui
window.geometry('450x400')
window.configure(background='white')
input=tk.StringVar()
output=tk.StringVar()
def compress(input,output):
	os.system("./hw8_B093040069 -c "+input+" -o "+output)  
def decompress(input,output):
    os.system("./hw8_B093040069 -u "+input+" -o "+output) 
f_Button=tk.Button(window,text='Compress',fg='black',command=lambda:compress(input.get(),output.get()))
f_Button.place(x=100,y=300)
input_enter=tk.Entry(window,width=10,textvariable=input)
input_enter.place(x=100,y=100)
output_enter=tk.Entry(window,width=10,textvariable=output)
output_enter.place(x=200,y=100)
s_Button=tk.Button(window,text='Decompress',fg='black',command=lambda:decompress(input.get(),output.get()))
s_Button.place(x=200,y=300)
tk.Label(text='輸入檔案名稱:').place(x=25,y=100)

window.mainloop()

