#include "base/json/json_reader.h"
#include "base/values.h"

int main() {
    base::JSONReader reader;
    char const * json_value = "{\"__name__\": \"abcde\\\\\\/\\u0AabF\\u05E9\\u05E7\\\"fgh\"}";
    printf("Attempting to parse: %s\n", json_value);
    base::Value * value =  reader.ReadToValue(json_value);
    base::DictionaryValue const * result = 0;
    std::string command;
    if(value && value->GetAsDictionary(&result)) {
        if(result && result->GetString("__name__", &command)) {
            printf("%s\n", command.c_str());
        }
    }
    else {
        printf("Failed to get string!\n");
    }
    return 0;
}
