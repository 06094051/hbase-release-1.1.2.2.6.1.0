# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

require 'hbase'
require 'shell'

include HBaseConstants

module Hbase
  class ConverterTest < Test::Unit::TestCase
    include TestHelpers

    non_ascii_text = '⻆⻇'
    non_ascii_row = '⻄'
    non_ascii_family = 'ㄹ'
    non_ascii_qualifier = '⻅'
    non_ascii_column = "#{non_ascii_family}:#{non_ascii_qualifier}"
    hex_text = '\xE2\xBB\x86\xE2\xBB\x87'
    hex_row = '\xE2\xBB\x84'
    hex_family = '\xE3\x84\xB9'
    hex_qualifier = '\xE2\xBB\x85'
    hex_column = "#{hex_family}:#{hex_qualifier}"

    def setup
      setup_hbase
    end

    def teardown
      shutdown
    end

    define_test 'Test scan for non-ascii data' do
      table_name = 'scan-test'
      create_test_table(table_name)
      # Write a record
      command(:put, table_name, 'r1', 'x:a', non_ascii_text)
      output = capture_stdout{ command(:scan, table_name) }
      # Encoded value not there by default
      assert(!output.include?(non_ascii_text), "Output was '#{output}'")
      # Hex-encoded value is there by default (manually converted)
      assert(output.include?(hex_text), "Output was '#{output}'")

      # Use the formatter method
      output = capture_stdout{ command(:scan, table_name, {'FORMATTER'=>'toString'}) }
      # Should have chinese characters
      assert(output.include?(non_ascii_text), "Output was '#{output}'")
      # Should not have hex-encoded string
      assert(!output.include?(hex_text), "Output was '#{output}'")

      # Use the formatter method + class
      output = capture_stdout{ command(:scan, table_name, {'FORMATTER'=>'toString', 'FORMATTER_CLASS' => 'org.apache.hadoop.hbase.util.Bytes'}) }
      # Should have chinese characters
      assert(output.include?(non_ascii_text), "Output was '#{output}'")
      # Should not have hex-encoded string
      assert(!output.include?(hex_text), "Output was '#{output}'")

      command(:disable, table_name)
      command(:drop, table_name)
      command(:create, table_name, non_ascii_family)

      command(:put, table_name, non_ascii_row, non_ascii_column, non_ascii_text)
      output = capture_stdout{ command(:scan, table_name) }
      # By default, get hex-encoded data
      assert(!output.include?(non_ascii_text), "Output was '#{output}'")
      assert(!output.include?(non_ascii_row), "Output was '#{output}'")
      assert(!output.include?(non_ascii_column), "Output was '#{output}'")
      assert(output.include?(hex_text), "Output was '#{output}'")
      assert(output.include?(hex_row), "Output was '#{output}'")
      assert(output.include?(hex_column), "Output was '#{output}'")

      # Use the formatter method
      output = capture_stdout{ command(:scan, table_name, {'FORMATTER'=>'toString'}) }
      # By default, get hex-encoded data
      assert(output.include?(non_ascii_text), "Output was '#{output}'")
      assert(output.include?(non_ascii_row), "Output was '#{output}'")
      assert(output.include?(non_ascii_column), "Output was '#{output}'")
      assert(!output.include?(hex_text), "Output was '#{output}'")
      assert(!output.include?(hex_row), "Output was '#{output}'")
      assert(!output.include?(hex_column), "Output was '#{output}'")

      # Use the formatter method + class
      output = capture_stdout{ command(:scan, table_name, {'FORMATTER'=>'toString', 'FORMATTER_CLASS' => 'org.apache.hadoop.hbase.util.Bytes'}) }
      # By default, get hex-encoded data
      assert(output.include?(non_ascii_text), "Output was '#{output}'")
      assert(output.include?(non_ascii_row), "Output was '#{output}'")
      assert(output.include?(non_ascii_column), "Output was '#{output}'")
      assert(!output.include?(hex_text), "Output was '#{output}'")
      assert(!output.include?(hex_row), "Output was '#{output}'")
      assert(!output.include?(hex_column), "Output was '#{output}'")
    end

    define_test 'Test get for non-ascii data' do
      table_name = 'get-test'
      create_test_table(table_name)
      # Write a record
      command(:put, table_name, 'r1', 'x:a', non_ascii_text)
      output = capture_stdout{ command(:get, table_name, 'r1') }
      # Encoded value not there by default
      assert(!output.include?(non_ascii_text), "Output was '#{output}'")
      # Hex-encoded value is there by default (manually converted)
      assert(output.include?(hex_text), "Output was '#{output}'")

      # use the formatter method
      output = capture_stdout{ command(:get, table_name, 'r1', {'FORMATTER'=>'toString'}) }
      # Should have chinese characters
      assert(output.include?(non_ascii_text), "Output was '#{output}'")
      # Should not have hex-encoded string
      assert(!output.include?(hex_text), "Output was '#{output}'")

      # use the formatter method + class
      output = capture_stdout{ command(:get, table_name, 'r1', {'FORMATTER'=>'toString', 'FORMATTER_CLASS' => 'org.apache.hadoop.hbase.util.Bytes'}) }
      # Should have chinese characters
      assert(output.include?(non_ascii_text), "Output was '#{output}'")
      # Should not have hex-encoded string
      assert(!output.include?(hex_text), "Output was '#{output}'")

      command(:disable, table_name)
      command(:drop, table_name)
      command(:create, table_name, non_ascii_family)

      # use no formatter (expect hex)
      command(:put, table_name, non_ascii_row, non_ascii_column, non_ascii_text)
      output = capture_stdout{ command(:get, table_name, non_ascii_row) }
      assert(!output.include?(non_ascii_text), "Output was '#{output}'")
      assert(!output.include?(non_ascii_column), "Output was '#{output}'")
      assert(output.include?(hex_text), "Output was '#{output}'")
      assert(output.include?(hex_column), "Output was '#{output}'")

      # use the formatter method
      output = capture_stdout{ command(:get, table_name, non_ascii_row, {'FORMATTER'=>'toString'}) }
      assert(output.include?(non_ascii_text), "Output was '#{output}'")
      assert(output.include?(non_ascii_column), "Output was '#{output}'")
      assert(!output.include?(hex_text), "Output was '#{output}'")
      assert(!output.include?(hex_column), "Output was '#{output}'")

      # use the formatter method + class
      output = capture_stdout{ command(:get, table_name, non_ascii_row, {'FORMATTER'=>'toString', 'FORMATTER_CLASS' => 'org.apache.hadoop.hbase.util.Bytes'}) }
      assert(output.include?(non_ascii_text), "Output was '#{output}'")
      assert(output.include?(non_ascii_column), "Output was '#{output}'")
      assert(!output.include?(hex_text), "Output was '#{output}'")
      assert(!output.include?(hex_column), "Output was '#{output}'")
    end
  end
end
