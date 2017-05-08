#include <KVS.py/Lib/Interpreter.h>
#include <KVS.py/Lib/String.h>
#include <KVS.py/Lib/Module.h>
#include <KVS.py/Lib/Dict.h>
#include <KVS.py/Lib/Callable.h>


int main( int argc, char** argv )
{
    kvs::python::Interpreter interpreter;

    const char* script_file_name = "hello"; // w/o '.py'
    kvs::python::Module module( script_file_name );
    kvs::python::Dict dict = module.dict();

    const char* func_name = "main"; // function defined in 'hello.py'
    kvs::python::Callable func( dict.find( func_name ) );
    func.call();

    return 0;
}
