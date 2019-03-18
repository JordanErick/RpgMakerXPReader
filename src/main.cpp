#include "reader/reader.hpp"

int main(int argc, char** argv)
{
    if (argc == 4)
    {
        const fs::path inputDir{ argv[1] };
        const fs::path outputDir{ argv[2] };
        const std::string format{ argv[3] };

        if (!fs::is_directory(inputDir))
        {
            fmt::print("'{}' is not a directory!\n", inputDir);
            return EXIT_FAILURE;
        }

        if (!fs::is_directory(outputDir))
        {
            fmt::print("'{}' is not a directory!\n", outputDir);
            return EXIT_FAILURE;
        }

        if (format == "json")
            rxdataToJSON(inputDir, outputDir);
        else if (format == "txt")
            rxdataToTxt(inputDir, outputDir);
        else
        {
            fmt::print("Invalid format!\n");
            return EXIT_FAILURE;
        }
    }
    else
        fmt::print("Usage: rmxp input_dir output_dir json|txt\n");

    return EXIT_SUCCESS;
}