#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>

#include <npy/npz.h>

namespace
{
    void test_file(std::filesystem::path& input_path)
    {
        std::shared_ptr<std::ifstream> input_path_stream = std::make_shared<std::ifstream>(input_path);
        npy::inpzstream npz_stream(input_path_stream);

        for (auto& filename : npz_stream.keys())
        {
            npy::header_info header_info = npz_stream.peek(filename);
            auto values = npz_stream.read<float>(filename);
        }
    }
}

int main()
{
    std::filesystem::path uncompressed_path(R"(<insert path to sample data>)");
    test_file(uncompressed_path);
	std::cout << "Uncompressed file processed successfully." << std::endl;

    std::filesystem::path compressed_path(R"(<insert path to sample data>)");
    test_file(compressed_path);
    std::cout << "Compressed file processed successfully." << std::endl;

	return 0;
}