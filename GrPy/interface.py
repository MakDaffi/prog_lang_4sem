from tkinter import *
from tkinter.ttk import Combobox
import drawing as dr
from tkinter import filedialog
from tkinter import messagebox

window = Tk()
window.title("Graphs")
window.geometry('850x450')


def click2(a, b):
    if a != '' and b != '' and txtb.get() != '' and txta.get() != '':
        dr.lin(int(txta.get()), int(txtb.get()), int(a), int(b))
    else:
        messagebox.showinfo('Error', 'Data entered incorrectly')


def click(a, b, c):
    if a != '' and b != '' and txtb.get() != '' and txta.get() != '' and c != '':
        dr.par(int(txta.get()), int(txtb.get()), int(a), int(b), int(c))
    else:
        messagebox.showinfo('Error', 'Data entered incorrectly')


def click3(f):
    if f != '' and txtb.get() != '' and txta.get() != '':
        dr.vvod(int(txta.get()), int(txtb.get()), f)
    else:
        messagebox.showinfo('Error', 'Data entered incorrectly')


# Действия для кнопки Enter
def click1():
    a = combo.get()
    if a == 'kx + b':
        btn = Button(window, text="Enter", bg="blue", fg="red", state=DISABLED)
        btn.grid(column=0, row=2)
        lbl1 = Label(window, text="Enter k", font=("Times New Roman", 30))
        lbl1.grid(column=0, row=3)
        txt = Entry(window, width=10)
        txt.grid(column=0, row=4)
        txt.focus()
        lbl1 = Label(window, text="Enter b", font=("Times New Roman", 30))
        lbl1.grid(column=0, row=5)
        txt1 = Entry(window, width=10)
        txt1.grid(column=0, row=6)
        btn = Button(window, text="Enter", bg="blue", fg="red", command=lambda: click2(txt.get(), txt1.get()))
        btn.grid(column=0, row=7)
    elif a == 'ax^2+bx+c':
        btn = Button(window, text="Enter", bg="blue", fg="red", state=DISABLED)
        btn.grid(column=0, row=2)
        lbl1 = Label(window, text="Enter a", font=("Times New Roman", 30))
        lbl1.grid(column=0, row=3)
        txt = Entry(window, width=10)
        txt.grid(column=0, row=4)
        txt.focus()
        lbl1 = Label(window, text="Enter b", font=("Times New Roman", 30))
        lbl1.grid(column=0, row=5)
        txt1 = Entry(window, width=10)
        txt1.grid(column=0, row=6)
        lbl1 = Label(window, text="Enter c", font=("Times New Roman", 30))
        lbl1.grid(column=0, row=7)
        txt2 = Entry(window, width=10)
        txt2.grid(column=0, row=8)
        btn = Button(window, text="Enter", bg="blue", fg="red", command=lambda: click(txt.get(), txt1.get(), txt1.get()))
        btn.grid(column=0, row=9)
    elif a == 'sin x':
        dr.sin(int(txta.get()), int(txtb.get()))
    elif a == 'x^3':
        dr.kyb(int(txta.get()), int(txtb.get()))
    elif a == 'cos x':
        dr.cos(int(txta.get()), int(txtb.get()))
    elif a == 'Enter your function':
        btn = Button(window, text="Enter", bg="blue", fg="red", state=DISABLED)
        btn.grid(column=0, row=2)
        lbl1 = Label(window, text="Enter f(x)", font=("Times New Roman", 30))
        lbl1.grid(column=0, row=3)
        txt = Entry(window, width=40)
        txt.grid(column=0, row=4)
        txt.focus()
        btn = Button(window, text="Enter", bg="blue", fg="red", command=lambda: click3(txt.get()))
        btn.grid(column=0, row=5)
    elif a == 'Open file':
        btn = Button(window, text="Enter", bg="blue", fg="red", state=DISABLED)
        btn.grid(column=0, row=2)
        f = filedialog.askopenfilename(filetypes=[("Text files", "*.txt")])
        dr.file(int(txta.get()), int(txtb.get()), f)
    else:
        messagebox.showinfo('Error', 'Data entered incorrectly')


lbl = Label(window, text="Choose function", font=("Times New Roman", 40))
lbl.grid(column=0, row=0)

# Установка панели выбор функции
combo = Combobox(window, height=30, width=30)
combo['values'] = ("kx + b", "sin x", "cos x", "x^3", "ax^2+bx+c", "Enter your function", "Open file")
combo.grid(column=0, row=1)

# Установка кнопки Enter
btn = Button(window, text="Enter", bg="blue", fg="red", height=1, width=15, command=click1)
btn.grid(column=0, row=2)

# Установка интервала
lbl = Label(window, text="Enter interval [a, b]", font=("Times New Roman", 40))
lbl.grid(column=3, row=0)
lbl = Label(window, text="a =", font=("Times New Roman", 30))
lbl.grid(column=2, row=2)
txta = Entry(window, width=15)
txta.grid(column=3, row=2)
lbl = Label(window, text="b =", font=("Times New Roman", 30))
lbl.grid(column=2, row=3)
txtb = Entry(window, width=15)
txtb.grid(column=3, row=3)

window.mainloop()