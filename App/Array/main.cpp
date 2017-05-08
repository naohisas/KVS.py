#include <KVS.py/Lib/Interpreter.h>
#include <KVS.py/Lib/String.h>
#include <KVS.py/Lib/Module.h>
#include <KVS.py/Lib/Float.h>
#include <KVS.py/Lib/Dict.h>
#include <KVS.py/Lib/Callable.h>
#include <KVS.py/Lib/Tuple.h>
#include <KVS.py/Lib/Array.h>
#include <kvs/ValueArray>

void Print( std::ostream& os, const kvs::ValueArray<kvs::Real32>& array )
{
    os << "{ " << std::flush;
    for ( size_t i = 0; i < array.size(); i++ )
    {
        os << array[i] << ", ";
    }
    os << "}" << std::endl;
}

int main( int argc, char** argv )
{
    kvs::python::Interpreter intepreter;

    const char* script_file_name = "array"; // w/o '.py'
    kvs::python::Module module( script_file_name );
    kvs::python::Dict dict = module.dict();

    const char* func_name = "main"; // function defined in 'hello.py'
    kvs::python::Callable func( dict.find( func_name ) );

    kvs::ValueArray<kvs::Real32> array( 3 );
    array[0] = 0.0f;
    array[1] = 1.0f;
    array[2] = 2.0f;
    Print( std::cout << "array = ", array );

    kvs::Real32 value = 2.0;
    std::cout << "value = " << value << std::endl;

    kvs::python::Tuple args( 2 );
    args.set( 0, kvs::python::Array( array ) );
    args.set( 1, kvs::python::Float( value ) );

    kvs::python::Array result = func.call( args );
    Print( std::cout << "array + value = ", kvs::ValueArray<kvs::Real32>( result ) );

    return 0;
}
