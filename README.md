# Ldays.exe

This is my fisrst malware!

Ldays.exe or LastDays.exe was coded in C++, batch, and VBScript. It took-me a week and a half to finish.

**Index**

- [Ldays.exe](#Ldays.exe)
- [Payloads](#Payloads)
	- [dec 31st payload](#dec%2031st%20payload)
- [Compiling](#Compiling)


# Payloads

This malware looks a lot like to the NoEscape.exe malware, then, the payloads appears in especific dates, here are the dates:

- **jan, 1st** - Some message boxes appears saying "Stupid error";

- **apr, 1st** - Some message boxes appears saying "HAPPY APRIL FOOLS!", while some colored squares appears in the desktop;

- **apr, 21st** - A tunnel like effect apeears in the desktop;

- **oct, 31st** - An always on top message box appears asking "Do you like windows?", if you answer "no", the message box appears again, if you answer "yes", the PC get a BSOD;

- **dec, 25th** - Some message box appears saying "Do you like lag?", while a lot of programs open;

- **dec, 30th** - A tunnel like effect appears in the desktop at the same time that some colored squares appears in the desktop, while a lot of programs open;

- **dec, 31st** - The bootloader gets erased, the notepad opens, the input get blocked, and some words are automatically typed in the notepad, then, the PC get a BSOD.


## dec 31st payload

The payload that appears in dec 31st is the most dangerous, because it erase your bootloader.

After the bootloader gets erased, the notepad open, the input get blocked,  and the following text is typed automatically:

```
LOOK
ITS DEC THIRDY FIRST

WHAT HAPPENED THIS YEAR:

JAN FIRST    MESSAGEBOX SPAM
APR FIRST    MESSAGEBOX SPAM SAYING   HAPPY APRIL FOOLS  , WHILE SOME VISUAL EFFECTS APPEARS
APR TWENTY FIRST    TUNNEL EFFECT ON DESKTOP
OCT THIRDY FIRST    BSOD
DEC TWENTY FIFTH    MESSAGEBOX SPAM WHILE A LOT OF PROGRAMS OPEN
DEC THIRTY    SOME VISUAL EFFECTS AND TUNNEL EFFECT APPEAR WHILE A LOT OF PROGRAMS OPEN

BUT NOW WHAT HAPPENS:

















ENJOY
```

When the text is fully typed, the PC get a BSOD.

# Compiling

I used Visual Studio 2022 community to code this malware. Here is the guide to compile this project.

 - **1)** First click [here](https://visualstudio.microsoft.com/pt-br/downloads/) to download [Visual Studio 2022](https://visualstudio.microsoft.com/pt-br/downloads/) installer;

 - **2)** Download the project in [Ldays/Source Code](https://github.com/robertohermenegildodias/Ldays/tree/main/Source%20Code);

 - **3)** In the installer, select "Desktop development with C++" and click in "install":
 
 ![](https://raw.githubusercontent.com/robertohermenegildodias/Ldays/main/Images/vs2022-installer-workloads.png)
 - **4)** When you open Visual Studio, select "Open a project or a solution" and open the .sln file that is in the folder that you downloaded:
 
 ![](https://raw.githubusercontent.com/robertohermenegildodias/Ldays/main/Images/vsmainscreen.png)

 - **5)** When you load the project solution, load all projects in the solution explorer, by clicking with the right mouse button in the project, then, clicking in the button called reload project;

- **6)** Right click in the solution, then, click in the button called "Compile solution";

All compiled files will be appear in the "Release" folder.
