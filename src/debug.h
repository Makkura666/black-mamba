if((int)glfwGetTime() == counter)
{
	clearScreen();
	std::cout << R"###(
	 _ ) | __ _  _   | | _  | \   | __ _ _  _  | |   __ _
	 _ \ |/ _` |/ _/ | |/ / | |\/ |/ _` |  ` \ | _ \/ _` |
	___/_|\__,_|\__\ |_|\_\ |_|  _|\__,_|_|_|_||.__/\__,_|
	)###";
	std::cout << "\n              ### - Gaming Engine - ###\n";
	printf ("| Time | %*f \n", 5, glfwGetTime());
	std::cout << "\n" << (int)glfwGetTime() << " " << counter;
    counter++;
}