#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include <limits>

int main() {
    using namespace ftxui;
 
    Element document = vbox({
        hbox({
            text("one") | border,
            text("two") | border | flex,
            text("three") | border | flex,
        }),

        gauge(0.25) | color(Color::Red),
        gauge(0.50) | color(Color::White),
        gauge(0.75) | color(Color::Blue),
    });
 
    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
    Render(screen, document);
    screen.Print();


#ifdef BUILD_DEBUG
    // prevent instant exit
    std::cout << "\nPress ENTER to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
}
