# Timer
Basic C++ timer (windows x64 dynamic library) done in Test-driven development

(Unit tests are included as secondary project - GTest)

## `setTimeout(EventCallback callback, std::chrono::seconds timeout)`

```c++
Timer timer = Timer();
timer.setTimeout([&](std::string_view str = "Cookoo!") -> bool {
    std::cout << "Tick Tock .. After 1s I'll print: " << str
        << " & return false value & stop\n";
    return false;
}, 1s);
```

## `setInterval(EventCallback callback, std::chrono::seconds interval);`

```c++
Timer timer = Timer();
timer.setInterval([&]() {
    std::cout << "Tick Tock .. After each 1s ...\n";
}, 1s);
```

## Sample Program

```c++
#include <iostream>
#include "Timer.h"

int main()
{
    Timer timer = Timer();

    timer.setTimeout([&]() {
        std::cout << "Tick Tock .. After 1s I'll do something & stop\n";
    }, 1s);

    timer.setInterval([&]() {
        std::cout << "Tick Tock .. After each 1s ...\n";
    }, 1s);

    // wait for 6 sec and than stop the timer
    std::this_thread::sleep_for(6s);

    timer.stop();
}
```

** Output**

```console
Tick Tock ..After 1s I'll do something & stop
Tick Tock ..After each 1s ...
Tick Tock ..After each 1s ...
Tick Tock ..After each 1s ...
Tick Tock ..After each 1s ...
Tick Tock ..After each 1s ...
```

### How to build?

```
Open solution "Timer.sln" with the Visual Studio 2019 and build
```

### How to use it?

```
1. Copy the "Timer.dll" library to your bin directory.
2. Include "Timer.h" to your source file.
3. Add "Timer.lib" to your project configuration: Linker->Input->Additional Dependencies.
```