#include <iostream>

#include <cstdlib>

void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

int main(int argc, const char *argv[]) 
{
    std::cout << R"###(
     _ ) | __ _  _   | | _  | \   | __ _ _  _  | |   __ _
 	 _ \ |/ _` |/ _/ | |/ / | |\/ |/ _` |  ` \ | _ \/ _` |
	___/_|\__,_|\__\ |_|\_\ |_|  _|\__,_|_|_|_||.__/\__,_|
    )###";
    std::cout << "\n              ### - Gaming Engine - ###\n";
    clear_screen();
    
	return 0;
}