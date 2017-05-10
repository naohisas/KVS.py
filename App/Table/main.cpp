#include <KVS.py/Lib/Interpreter.h>
#include <KVS.py/Lib/String.h>
#include <KVS.py/Lib/Module.h>
#include <KVS.py/Lib/Float.h>
#include <KVS.py/Lib/Dict.h>
#include <KVS.py/Lib/Callable.h>
#include <KVS.py/Lib/Tuple.h>
#include <KVS.py/Lib/Table.h>
#include <kvs/ValueTable>

void Print( std::ostream& os, const kvs::ValueTable<kvs::Real32>& table )
{
    const size_t nrows = table[0].size();
    const size_t ncols = table.columnSize();

    os << std::endl;
    for ( size_t i = 0; i < nrows; i++ )
    {
        os << "{ " << std::flush;
        for ( size_t j = 0; j < ncols; j++ )
        {
            os << table[j][i] << ",";
        }
        os << "}" << std::endl;
    }
}

int main( int argc, char** argv )
{
    kvs::python::Interpreter intepreter;

    const char* script_file_name = "table"; // w/o '.py'
    kvs::python::Module module( script_file_name );
    kvs::python::Dict dict = module.dict();

    const char* func_name = "main"; // function defined in 'hello.py'
    kvs::python::Callable func( dict.find( func_name ) );

    kvs::ValueTable<kvs::Real32> table( 2, 2 );
    table[0][0] = 0.0f; table[1][0] = 1.0f;
    table[0][1] = 2.0f; table[1][1] = 3.0f;
    Print( std::cout << "table = ", table );

    kvs::python::Tuple args( 1 );
    args.set( 0, kvs::python::Table( table ) );

    kvs::python::Table result = func.call( args );
    Print( std::cout << "table = ", kvs::ValueTable<kvs::Real32>( result ) );

    return 0;
}
