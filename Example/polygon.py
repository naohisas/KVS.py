import os
import sys
import optparse

sys.path.append('../Release')
import kvs

def main():
    parser = optparse.OptionParser( usage="%prog <filename>" )
    ( opts, args ) = parser.parse_args()

    if len( args ) is 0:
        parser.print_help()
        sys.exit(1)

    file = args.pop()

    app = kvs.Application()
    screen = kvs.Screen( app )

    # Polygon rendering
    importer = kvs.PolygonImporter()
    object = importer.execute( file )
    renderer = kvs.PolygonRenderer()

    screen.registerObject( object, renderer )
    screen.setGeometry( 0, 0, 512, 512 )
    screen.setTitle( "KVS Python" )
    screen.show()

    app.run()

if __name__ == "__main__":
    main()
