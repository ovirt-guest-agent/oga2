#include <tut/tut.hpp>
#include <tut/tut_reporter.hpp>
#include <stdio.h>

using tut::reporter;
using tut::groupnames;

namespace tut {
    test_runner_singleton runner;
}

void usage(char const * app)
{
    printf
    (
        "ovirt-guest-agent unit test runner.\n"
        "Usage: %s [regression] | [list] | [group] [test]\n"
        "       list - Lists all groups\n"
        "       regression - Runs all tests\n"
        "       group - Runs all tests in the specified group\n"
        "       group test - Runs the specified test in the specified group\n",
        app
    );
}

int main(int argc, char const *argv[])
{
    reporter visitor;

    if(argc < 2 || argc > 3) {
        usage(argv[0]);
    }
    else {
        tut::runner.get().set_callback(&visitor);
        try {
            std::string first_arg = argv[1];
            if(argc == 2) {
                if(first_arg == "regression") {
                    tut::runner.get().run_tests();
                }
                else if(first_arg == "list") {
                    printf("Registered groups:\n");
                    groupnames gl = tut::runner.get().list_groups();
                    groupnames::const_iterator i = gl.begin(), e = gl.end();
                    for(; i != e; ++i) {
                        printf("  - %s\n", i->c_str());
                    }
                }
                else {
                    tut::runner.get().run_tests(first_arg);
                }
            }
            else if(argc == 3) {
                tut::test_result result;
                tut::runner.get().run_test(first_arg, ::atoi(argv[2]), result);
            }
        }
        catch(std::exception const & e) {
            printf("TUT raised an exception: %s\n", e.what());
        }
    }
    return 0;
}

