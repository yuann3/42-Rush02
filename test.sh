# https://gist.github.com/mohanpedala/1e2ff5661761d3abd0385e8223e16425
set -o pipefail

BINARY=rush-02

TEST_DIR=tests

TEST_FILE=test.sh
OUTPUT_FILE=output.txt
EXPECT_FILE=expect.txt

root_dir=$(pwd)

for case in ${TEST_DIR}/*; do
  cd $case

  # Print test case
  echo "=== ${case} ==="
  echo "$> $(cat $TEST_FILE)"

  # Run test case
  BINARY="${root_dir}/${BINARY}" sh $TEST_FILE > $OUTPUT_FILE

  # Compare expect with output
  diff -u $EXPECT_FILE $OUTPUT_FILE

  cd $root_dir
done
