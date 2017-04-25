#include <Python.h>


int main( int argc, char** argv )
{
    Py_Initialize();

    const char* script_file_name = "hello"; // w/o '.py'
    PyObject* module_name = PyString_FromString( script_file_name );
    PyObject* module = PyImport_Import( module_name );
    PyObject* dic = PyModule_GetDict( module );

    const char* func_name = "main"; // function defined in 'hello.py'
    PyObject* main_func = PyDict_GetItemString( dic, func_name );
    PyObject_CallObject( main_func, NULL );

    Py_Finalize();

    return 0;
}
