// #include <iostream>
// #include <fstream>
// using namespace std;

// int main() {
//     ifstream file("example.txt", ios::in);
//     file.seekg(9, ios::beg);  // Move the read pointer to the 5th byte from the start
//     char ch;
//     file.get(ch);            // Read the character at the new position
//     cout << "Character at 5th byte: " << ch << endl;
//     file.close();
//     return 0;
// }


#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("example.txt",ios::in | ios::out);
    file.seekp(2, ios::beg);  // Move the write pointer to the 10th byte
    file << "yash ";           // Overwrite text starting from the 10th byte
    file.close();
    return 0;
}


// #include <iostream>
// #include <fstream>
// using namespace std;

// int main() {
//     ifstream file("example.txt", ios::in);
//     file.seekg(1, ios::beg);        // Move to the 15th byte
//     streampos pos = file.tellg();    // Get the current position
//     cout << "Current read position: " << pos << endl;
//     file.close();
//     return 0;
// }


// #include <iostream>
// #include <fstream>
// using namespace std;

// int main() {
//     ofstream file("example.txt", ios::out);
//     file.seekp(20, ios::beg);        // Move to the 20th byte
//     streampos pos = file.tellp();    // Get the current position
//     cout << "Current write position: " << pos << endl;
//     file.close();
//     return 0;
// }
