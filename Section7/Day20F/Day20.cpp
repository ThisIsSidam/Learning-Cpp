// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 16/05/2022
//
// Day20 Of Learning C++
// --------------------------------------

/*
* --The Proper Way of Making Classes--
* With classes, files get enormously big, not in size but in the respect of code we write in it. We won't know it
* yet but once we start making big projects, we'll know it. So, things are done in separate files. The main code 
* is written in the primary file, the class is in a different one and the class methods are in a different file.
* There will be 2 .cpp and one .h/.hpp file. One .cpp file is our primary and the other one contains methods and
* so the last one, the .h (We'll use .h) contains the classes. I'll explain the whole process and then you can 
* see it.
* 
* First we gotta find a way of making class files. Every IDE has a way. Using it the IDE will automatically 
* generate the two other files. I'm currently using VS Code, here I installed an extension. Search the net for 
* how you can create class files on the IDE you use.
*
* Now, while creating the file you must have given the name for it and have gotten the two needed files and they
* will have the same name, just different extension. The .h file containing the class is called the implementation
* file and the .cpp file other than the primary file containing the methods is called the Specification file. To 
* use these files with the primary file, you have to include them, like you include iostream file, but not exactly. 
* Angular bracks are used with system files like string and iostream, but with files that are local, we need to
* use Double Quotes. 
* 
* The .h will have lots of preprocessor directives. Those directives are called Include Guard, when we include 
* these files with multiple projects, we'll recieve duplicate declaration error. To save ourselves from that, we
* use these Include Guards. There two types of these, and both of them are included in the .h file. First is the 
* 
* #ifndef file_name_
* #define file_name_
* code
* #endif
* 
* The ifndef stands for "If not defined", it will have the filename with underscores around it after it. And the 
* next line is also similar. After that is code and endif at the end. The other one is
* 
* #pragma once
*
* Yup, just that. The only drawback is that it is not supported everywhere. So not used that much yet. We will
* not use it for now. And will write out class in that file.
*
* Next we'll see that there is some stuff we haven't yet learned. They are under the access modifiers and are of
* the name of the class and one is with a tilde(~). Those are Constructors and Destructors. We'll learn that after
* a while, for now we'll just remove them.
* 
* The next thing for us to do is define the methods whose prototypes we left in the implementation file. It will 
* have the .h file included beforehand. And those Constructors and Destructors too, we'll remove them again. And
* define our methods. And then we are good to go.
*/


#include <iostream>
#include <string>
#include "Day20Additional.h"

int main()
{
    Day20Additional hero;
    hero.set_name("Hero");
    std::cout << hero.get_name() << std::endl;

    hero.set_hp(89);
    std::cout << hero.get_hp() << std::endl;

    hero.double_hp();
    std::cout << hero.get_hp() << std::endl;

    hero.null_hp();
    std::cout << hero.get_hp() << std::endl;
    
    return 0;
}