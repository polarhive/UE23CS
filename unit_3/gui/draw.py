import tkinter
root = tkinter.Tk()
root.geometry('500x500')
cv=tkinter.Canvas(root, width='400', height='300', bg='pink')
cv.create_line(20,50,100,200, fill='red')
cv.pack()
root.mainloop()
