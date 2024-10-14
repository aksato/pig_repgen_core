#include <string>
#include <cstdlib>
#include <iostream>
#include <CLI/CLI.hpp>

#include "db.h"
#include "repgen/repgen.h"

int main(int argc, char *argv[])
{
    // Initialize CLI11 app
    CLI::App app{"Report Generator"};
    argv = app.ensure_utf8(argv);

    // Variables to store CLI arguments
    std::string dbFile;
    std::string outputFile;

    // Define options with CLI11
    app.add_option("-d,--db", dbFile, "Path to the SQLite database file")
        ->required()
        ->check(CLI::ExistingFile); // Ensure the file exists

    app.add_option("-o,--output", outputFile, "Path to the output PDF file")
        ->required();

    // Parse CLI arguments
    CLI11_PARSE(app, argc, argv);

    // Generate latex as string
    std::string renderedLatex = repgen::generateAnomaliesSummary(dbFile);

    // Compile LaTeX to PDF using a generated .tex file
    if (!repgen::compileToPdf(renderedLatex, outputFile))
    {
        std::cerr << "Error writing to file!" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
