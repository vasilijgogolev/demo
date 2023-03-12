PLATFORM=""

function check_platform() { 
	if [ "$PLATFORM" != "" ]; then
		echo choose only one platform
		exit
	fi

	var="$1"
	PLATFORM="${var:1}"
}


while [ "$1" != "" ]; do
	case "$1" in
		"-win32" | \
		"-mac")
			check_platform $1
		;;
		*)
			echo Unknown command $1
			exit
		;;
	esac

    shift
done

if [ "$PLATFORM" == "mac" ]; then
	echo -- build MACOS project

	mkdir -p build/mac
	cd build/mac

	cmake ../.. -G Xcode -DMACOS=1
fi

if [ "$PLATFORM" == "win32" ]; then
	echo -- building WIN32 project

	mkdir -p build/win32
	cd build/win32

	cmake ../../ -G"Visual Studio 16 2019" -AWin32 -DWIN32=1
fi

