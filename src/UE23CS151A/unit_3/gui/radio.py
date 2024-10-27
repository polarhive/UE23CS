import tkinter
root = tkinter.Tk()
root.geometry('500x500')
l1=tkinter.Label(root,text="select your choice: ")
l2=tkinter.Label(root,text="")
val1=tkinter.StringVar()
def select():
    v1=val1.get()
    l2.configure(text=f"option: {v1} ")
r1=tkinter.Radiobutton(root, text="C", variable=val1, value='C', command=select)
r2=tkinter.Radiobutton(root, text="Py", variable=val1, value='py', command=select)

l1.pack()
l2.pack()
r1.pack()
r2.pack()
root.mainloop()
