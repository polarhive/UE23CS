import tkinter
root = tkinter.Tk()
root.geometry('500x500')
cv=tkinter.Canvas(root, width='400', height='400')
img=tkinter.PhotoImage(file='a.png')
lab1=tkinter.Label(image=img)
lab1.pack()
cv.pack()
root.mainloop()
