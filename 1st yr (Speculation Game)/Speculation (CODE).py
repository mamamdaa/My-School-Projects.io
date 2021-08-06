from tkinter import *
from tkinter import messagebox
import winsound

class speculation:
    def __init__(self, root):
        self.main = root
        self.main.resizable(0, 0)
        self.main.geometry("1100x600")
        self.text1 = None
        self.text2 = None
        self.text3 = None
        self.entry = None
        self.text4 = None
        self.but = None
        self.reset = None
        self.photo = PhotoImage(file = "sign-out.png")
        self.photo1 = PhotoImage(file="sign-in.png")
        self.photo2 = PhotoImage(file="keyboard-key-enter.png")
        self.missingwords = ["T__NT__", "__TT__", "_A__A_", "__T__", "____E", "L___L", "L__TB__", "__N_", "T__T", "C_EC__UTT_N"]
        self.words = ["tkinter","button", "canvas", "entry", "frame", "label", "listbox", "menu", "text", "checkbutton"]
        self.hint = [
              "the Python interface to the Tk GUI toolkit shipped with Python."
            , "widget is used to display or make a buttons in your application."
            , "widget is used to draw shapes, such as polygon, rectangles etc. "
            , "widget display's a single line for accepting values from a user."
            , "this  widget  is used as a container to organize other widgets ."
            , "widget is used to provide a single-line caption for other widgets."
            , "in this widget it's used to provide a list of options to a user."
            , "widget used to provide commands are contained inside Menubutton."
            , "this widget is used to provide a display text in multiple lines."
            , "this widget is used to display a number of options as checkboxes."]
        self.questionnumber = 0
        self.score = 0
        self.menu()


    def menu(self):
        self.main.title("Speculation")
        self.main.configure(background="gray")
        self.e = Label(self.main, text="     THE", font="broadway 75 bold", bg="gray", fg="gray12")
        self.e.grid(row=0,)
        self.a = Label(self.main, text="     SPECULATION", font="broadway 75 bold", bg="gray", fg="gray12")
        self.a.grid(row=1,)
        self.b = Label(self.main, text="NOTE!!", font="arial 40 bold", fg="darkred", bg="gray")
        self.b.grid(row=2, sticky="W")
        self.c = Label(self.main, text="The game topic is all about TKINTER before you start the game, ", font="arial 25 bold", fg="brown", bg="gray")
        self.c.grid(row=3, sticky="W")
        self.dd = Label(self.main, text="make sure that you have an idea about TKINTER!!!!", font="arial 25 bold", height=3, fg="brown", bg="gray")
        self.dd.grid(row=4, sticky="W")
        self.d = Label(self.main, text="You will be given 30 seconds to guess the missing letter.", font="arial 25 bold", fg="brown", bg="gray")
        self.d.grid(row=5, sticky="W")
        self.f = Label (self.main, text="Press to start the game", font="arial 15 bold", fg="gray88", bg="gray10")
        self.f.grid(row=6, column=0)
        self.p = Button(self.main, image = self.photo1, command=self.start)
        self.p.grid(row=7, columnspan=1)
        self.g = Label(self.main, text="Press to close", font="arial 15 bold", fg="gray88", bg="gray10")
        self.g.grid(row=6, sticky="E")
        self.q = Button(self.main, image=self.photo, command=self.main.quit)
        self.q.grid(row=7, sticky="E")

    def start(self):
        self.a.destroy(), self.b.destroy(), self.c.destroy(), self.d.destroy(), self.p.destroy(), self.e.destroy(), self.f.destroy()
        self.q.destroy(), self.g.destroy(), self.dd.destroy()
        winsound.PlaySound("begin", winsound.SND_FILENAME)
        self.thegame()


    def timer(self):
        global event
        if self.clocker < 6:
            self.text5.config(fg="Red")
        self.text5.config(text="Time Left: " + str(self.clocker), font="ebrima 50 bold")
        self.clocker -= 1
        event = self.main.after(1000, self.timer)
        if self.clocker == -1:
            self.main.after_cancel(event)
            winsound.PlaySound("end", winsound.SND_ASYNC)
            messagebox.showinfo("Timer", "Time's Up! the correct answer is: " + str(self.words[self.questionnumber]) +"\nProceed to next question")
            self.frame.grid_forget()
            self.question()
            self.thegame()


    def question(self):
        self.questionnumber +=1
        while self.questionnumber >=10:
            self.frame.destroy()
            self.score += 1
            self.totals = self.score
            self.totals -= 1
            messagebox.showinfo("Calculating", "GAME OVER!!!\nLets Calculate your total score")
            messagebox.showinfo("Total Score", "\t\t  : " + str(self.totals)+ "/10 :\t\t  \n \tPRESS OK TO EXIT")
            self.main.quit()
            break


    def thegame(self):
        self.clocker = 30
        self.frame = LabelFrame(self.main)
        self.frame.grid()
        self.frame.configure(background="gray")
        winsound.PlaySound("minute", winsound.SND_ASYNC)
        self.text3 = Label(self.frame, text="HINT:", font="arial 50 bold", fg="darkred", bg="gray")
        self.text3.grid(row=4, sticky="W")
        self.text9 = Label(self.frame, text=str(self.hint[self.questionnumber]), font="arial 25 bold", fg="brown", bg="gray", width=55)
        self.text9.grid(row=5, sticky="W")
        self.text1 = Label(self.frame, text=self.missingwords[self.questionnumber], font="candara 50 bold", fg="green", bg="gray")
        self.text1.grid(row=2, column=0)
        self.text2 = Label(self.frame, text="       Guess the missing letter: ", font="ebrima 50 bold", bg="gray", fg="gray12")
        self.text2.grid(row=0, column=0)
        self.text5 = Label(self.frame, text="Time Left: " + str(self.clocker), bg="gray", fg="gray12")
        self.text5.grid(row=8, sticky=W)
        self.text4 = Label(self.frame,  font="ebrima 50 bold", text="Score: " + str(self.score), bg="gray", fg="gray12")
        self.text4.grid(row=4, sticky="E")
        self.entry = Entry(self.frame, font="candara 50 bold")
        self.entry.grid(row=3)
        self.text8 = Label(self.frame, text="Press to ENTER", bg="gray", font="arial 10 bold")
        self.text8.grid(row=6, )
        self.but = Button(self.frame, image=self.photo2, command=self.missing)
        self.but.grid(columnspan=3, row=7)
        self.timer()

    def missing(self):
        worddup = ""
        if len(self.entry.get()) > 1:
            self.entry.delete(0, 'end')
            messagebox.showinfo("Quiz", "ANSWER TOO LONG!!!!")
        elif self.entry.get().lower() in self.words[self.questionnumber].lower():
            if self.entry.get().lower() in self.missingwords[self.questionnumber].lower():
                self.entry.delete(0, 'end')
                messagebox.showinfo("Quiz", "INVALID!!!!\nPLEASE CHECK THE LETTER")
            else:
                for count in range(len(self.missingwords[self.questionnumber])):
                    if self.entry.get().lower() == self.words[self.questionnumber][count]:
                        iter = 0
                        for letter in self.missingwords[self.questionnumber]:
                            if count == iter:
                                worddup += self.entry.get().upper()
                            else:
                                worddup += str(letter)
                            iter += 1
                        self.missingwords[self.questionnumber] = worddup
                self.text1.config(text=self.missingwords[self.questionnumber])
                self.entry.delete(0, 'end')



        else:
            self.entry.delete(0, 'end')
            messagebox.showinfo("Word", "Wrong!!!!!")
        if self.missingwords[self.questionnumber] == self.words[self.questionnumber].upper():
            self.main.after_cancel(event)
            winsound.PlaySound("correct", winsound.SND_FILENAME)
            messagebox.showinfo("Quiz", "You Guessed the Word! Ready for the next question?")
            self.frame.grid_forget()
            self.score +=1
            self.question()
            self.thegame()




speculation(Tk())
mainloop()