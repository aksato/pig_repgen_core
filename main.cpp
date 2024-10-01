#include <string>
#include <cstdlib>
#include <iostream>

#include "db.h"
#include "repgen/repgen.h"

int main(int argc, char *argv[])
{
    // Get name from line edit UI
    std::string dbFile = "analysis.sqlite";

    // Generate latex as string
    std::string renderedLatex = repgen::generateAnomaliesSummary(dbFile);

    // Compile LaTeX to PDF using a generated .tex file
    if (!repgen::compileToPdf(renderedLatex, "output.pdf"))
    {
        std::cerr << "Error writing to file!" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
