#include "extern.h"
#include "antlr4-runtime.h"
#include "MyGrammarBaseListener.h"
#include "MyGrammarLexer.h"
#include "MyGrammarParser.h"

using namespace myparser;
using namespace antlr4;
using namespace antlr4::tree;

extern "C" {
    uint8_t run_parser(const char * input) {
        try {
            ANTLRInputStream stream(input);
            MyGrammarLexer lexer(&stream);
            CommonTokenStream tokens(&lexer);
            MyGrammarParser parser(&tokens);

            ParseTree * tree = parser.root();
            ParseTreeWalker walker;
            MyGrammarBaseListener listener;
            walker.walk(&listener, tree);
        } catch (std::exception& e) {
            return 0;
        }

        return 1;
    }
}