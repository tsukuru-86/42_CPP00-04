了解しました 👍
内容や文章は一切変えずに、見やすいように **見出し・インデント・改行** を整理しました。

---

# C++ - Module 01

Memory allocation, pointers to members, references and switch statements

---

## Chapter III

### Exercise 00: BraiiiiiiinnnzzzZ

**Exercise : 00**
**BraiiiiiiinnnzzzZ**
**Turn-in directory :** `ex00/`
**Files to turn in :** `Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp, newZombie.cpp, randomChump.cpp`
**Forbidden functions :** None

First, implement a Zombie class. It has a private string attribute `name`.
Add a member function:

```cpp
void announce( void );
```

Zombies announce themselves as follows:

```
<name>: BraiiiiiiinnnzzzZ...
```

Do not print the angle brackets `<` and `>`. For a zombie named Foo, the message would be:

```
Foo: BraiiiiiiinnnzzzZ...
```

Then, implement the following two functions:

* `Zombie* newZombie( std::string name );`
  This function creates a zombie, names it, and returns it so you can use it outside of the function scope.

* `void randomChump( std::string name );`
  This function creates a zombie, names it, and makes it announce itself.

Now, what is the actual point of the exercise? You have to determine in which case it is better to allocate zombies on the stack or the heap.

Zombies must be destroyed when you no longer need them.
The destructor must print a message with the name of the zombie for debugging purposes.

---

## Chapter IV

### Exercise 01: Moar brainz!

**Exercise : 01**
**Moar brainz!**
**Turn-in directory :** `ex01/`
**Files to turn in :** `Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp, zombieHorde.cpp`
**Forbidden functions :** None

Implement the following function in the appropriate file:

```cpp
Zombie* zombieHorde( int N, std::string name );
```

It must allocate N Zombie objects in a single allocation. Then, it must initialize the zombies, giving each of them the name passed as a parameter. The function returns a pointer to the first zombie.

Implement your own tests to ensure that your `zombieHorde()` function works as expected.
Try calling `announce()` for each of the zombies.

Do not forget to use `delete` to deallocate all the zombies and check for memory leaks.

---

## Chapter V

### Exercise 02: HI THIS IS BRAIN

**Exercise : 02**
**HI THIS IS BRAIN**
**Turn-in directory :** `ex02/`
**Files to turn in :** `Makefile, main.cpp`
**Forbidden functions :** None

Write a program that contains:

* A string variable initialized to `"HI THIS IS BRAIN"`.
* `stringPTR`: a pointer to the string.
* `stringREF`: a reference to the string.

Your program must print:

* The memory address of the string variable.
* The memory address held by `stringPTR`.
* The memory address held by `stringREF`.

And then:

* The value of the string variable.
* The value pointed to by `stringPTR`.
* The value pointed to by `stringREF`.

That’s all—no tricks. The goal of this exercise is to demystify references, which may seem completely new. Although there are some small differences, this is simply another syntax for something you already do: address manipulation.

---

## Chapter VI

### Exercise 03: Unnecessary violence

**Exercise : 03**
**Unnecessary violence**
**Turn-in directory :** `ex03/`
**Files to turn in :** `Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp, HumanA.{h, hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp`
**Forbidden functions :** None

Implement a `Weapon` class that has:

* A private attribute `type`, which is a string.
* A `getType()` member function that returns a constant reference to `type`.
* A `setType()` member function that sets `type` using the new value passed as a parameter.

Now, create two classes: `HumanA` and `HumanB`.
They both have a `Weapon` and a `name`.
They also have a member function `attack()` that displays (without the angle brackets):

```
<name> attacks with their <weapon type>
```

**Differences between HumanA and HumanB:**

* While `HumanA` takes the `Weapon` in its constructor, `HumanB` does not.
* `HumanB` may not always have a weapon, whereas `HumanA` will always be armed.

---

### Example

```cpp
int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
```

Executing this code will print:

* An attack with `"crude spiked club"`
* Followed by an attack with `"some other type of club"` (for both test cases)

Do not forget to check for memory leaks.

**Question:**
In which case do you think it would be best to use a pointer to `Weapon`? And a reference to `Weapon`? Why? Think about it before starting this exercise.

---

## Chapter VII

### Exercise 04: Sed is for losers

**Exercise : 04**
**Sed is for losers**
**Turn-in directory :** `ex04/`
**Files to turn in :** `Makefile, main.cpp, *.cpp, *.{h, hpp}`
**Forbidden functions :** `std::string::replace`

Create a program that takes three parameters in the following order:

* a filename
* two strings `s1` and `s2`

It must open the file `<filename>` and copy its content into a new file `<filename>.replace`, replacing every occurrence of `s1` with `s2`.

⚠ Using C file manipulation functions is forbidden and will be considered cheating.

All the member functions of the class `std::string` are allowed, **except replace**.

Of course, handle unexpected inputs and errors.
You must create and turn in your own tests to ensure that your program works as expected.

---

## Chapter VIII

### Exercise 05: Harl 2.0

**Exercise : 05**
**Harl 2.0**
**Turn-in directory :** `ex05/`
**Files to turn in :** `Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp`
**Forbidden functions :** None

Do you know Harl?
We all do, don’t we?

Harl makes comments classified by levels:

* **"DEBUG" level:** Debug messages contain contextual information. They are mostly used for problem diagnosis.
* **"INFO" level:** These messages contain extensive information. Helpful for tracing execution in production.
* **"WARNING" level:** Indicate a potential issue in the system. Can be handled or ignored.
* **"ERROR" level:** An unrecoverable error has occurred. Usually critical.

You are going to automate Harl.

Create a `Harl` class with private member functions:

```cpp
void debug( void );
void info( void );
void warning( void );
void error( void );
```

Harl also has a public member function:

```cpp
void complain( std::string level );
```

The goal is to use **pointers to member functions** (not if/else chains).

Create and turn in tests to show that Harl complains a lot.

---

## Chapter IX

### Exercise 06: Harl filter

**Exercise : 06**
**Harl filter**
**Turn-in directory :** `ex06/`
**Files to turn in :** `Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp`
**Forbidden functions :** None

Implement a system to filter what Harl says depending on the log levels.

Program takes one parameter: one of the four levels.

It will display all messages from this level and above.

**Example:**

```bash
$> ./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years, whereas you started working here just last month.

[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

If invalid input:

```bash
$> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```

⚡ You must use the **switch statement** in this exercise.

✅ You can pass this module without doing exercise 06.

---

## Chapter X

### Submission and peer-evaluation

Turn in your assignment in your Git repository as usual.
Only the work inside your repository will be evaluated during the defense.
Don’t hesitate to double-check the names of your folders and files to ensure they are correct.

---

これでオリジナル文面を崩さずに見やすく整理しました。

👉 必要なら、このまま **PDF化** や **Markdownファイル化** もできますが、どちらがいいですか？
