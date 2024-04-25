#include <iostream>
#include <string>
#include <sstream> // string stream

void istringstream_test()
{
    std::cout << __func__ << "\n";

    std::string a("1 2 3");

    std::istringstream my_stream(a); // input string stream object from <sstream> header

    int n;
    my_stream >> n; // can be streamed and stored using the "extraction operator": >>.
    std::cout << n << "\n";
}

void use_isstringstream_as_boolen_read_all()
{
    std::cout << __func__ << "\n";
    std::string a("1 2 3");
    std::istringstream theStream(a);
    int n;
    while (theStream)
    {
        theStream >> n;
        if (theStream)
        {
            std::cout << "That stream was successful: " << n << "\n";
        }
        else
        {
            std::cout << "That stream was NOT successful!"
                      << "\n";
        }
    }
}

void common_way_to_use_istringstream_in_while()
{
    std::cout << __func__ << "\n";
    std::istringstream myreader("1 2 3");
    int n;
    while (myreader >> n)
    {
        std::cout << "read: " << n << "\n";
    }
    std::cout << "The stream has failed or ended."
              << "\n";
}

void string_with_MIX_types_not_space()
{
    /*
In the stream example above, the string contained only whitespaces
and characters which could be converted to ints.

If the string has mixed types, more care is needed to process the string.
In the following example,
the type char is used, which is a type that can hold only a single ASCII character.
*/
    std::cout << __func__ << "\n";

    std::string b("1,2,3,4,6q7p8o9");
    std::istringstream mixstring(b);
    // need two type of tmp value
    char c;
    int n;
    /*
        !! notice that the 9 was not printed

        mixstring >> n >> c

        tried to stream an int followed by a char.
        Since there was no char after the 9, the stream
        failed and the while loop exited.
    */
    // lw: this code is still too tricky. because the format string has to satisfy the critirie of int + char.
    while (mixstring >> n >> c)
    {
        std::cout << "read int: " << n << ", read char: " << c << "\n";
    }
    std::cout << "The stream has failed or ended."
              << "\n";
}

int main()
{
    // stream with all INT type
    // istringstream_test();
    // use_isstringstream_as_boolen_read_all();
    // common_way_to_use_istringstream_in_while();

    // //stream with MIX type
    // //the INT spreated by only one char not space
    string_with_MIX_types_not_space();
}
