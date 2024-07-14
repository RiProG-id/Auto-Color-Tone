#!/bin/bash
if ! command -v zip >/dev/null 2>&1; then
	echo "zip is not installed. Please install zip to proceed."
	exit 1
fi
if ! command -v clang >/dev/null 2>&1; then
	echo "clang is not installed. Please install clang to proceed."
	exit 1
fi
mydir=$(dirname "$(realpath "$0")")
version=$(grep version= "$mydir"/src/R/module.prop | awk -F'=' '{print $2}')
if [ ! -d "$mydir"/output ]; then
	mkdir "$mydir"/output
fi
clang -O3 "$mydir"/src/R/source.c -o "$mydir"/src/R/main
if [ -d "$mydir"/R ]; then
	rm -rf "$mydir"/R
fi
mkdir -p "$mydir"/R/common
mkdir -p "$mydir"/R/META-INF/com/google/android
cp "$mydir"/src/R/install.sh "$mydir"/R
mv "$mydir"/src/R/main "$mydir"/R
cp "$mydir"/src/R/module.prop "$mydir"/R
cp "$mydir"/src/R/service.sh "$mydir"/R/common
cp "$mydir"/src/R/source.c "$mydir"/R
cp "$mydir"/src/R/update-binary.sh "$mydir"/R/META-INF/com/google/android/update-binary
echo "#MAGISK" >"$mydir"/R/META-INF/com/google/android/updater-script
cd "$mydir"/R || exit
zip -r ./"Auto Color Tone $version R.zip" ./*
cd "$mydir" || exit
mv "$mydir/R/Auto Color Tone $version R.zip" "$mydir"/output
rm -rf "$mydir"/R
