# ruby template for server and gems distribution

Deploy your own gem server along with your custom gems

#### install the gem 
To install the gem localy and run it from any directory

From 
```bash
/my_gem_box/my_new_gem/
```
Run
```bash
gem build my_new_gem.gemspec
gem install ./my_new_gem-0.0.0.gem
```
Then type ``my_new_gem`` from anywhere in the dir to run your new program.

#### run the gem server

To run the gem server and install from "local" server
```bash
gem install geminabox
gem install puma
gem install rake
```

From 
```bash
/my_sqlite/geminabox
```
Run 
```bash
rackup
```
Access it from local http://localhost:9292


#### Test your new gem

To run automated test on my_new_gem
```bash
gem install rake
```
From
``` bash
/my_gem_box/my_new_gem/
```
Run
```bash
rake
```

You can write your own test using subs and mocks, here is an example : 

```ruby
require 'minitest/autorun'
require 'mocha/minitest'
require_relative '../lib/my_sqlite'

class MySqliteInstanceTest < Minitest::Test

    def test_cli_select
        quit = ["quit",";"]
        test_array = [
            ["select first_name\nfrom data.csv\nwhere job = Engineer",";"],
            ["select first_name, last_name","from data.csv","where job = Engineer",";"],
            ["select first_name,last_name\nfrom data.csv\nwhere job = Engineer",";"],
            ["select *\nfrom data.csv\nwhere job = Engineer",";"],
            ["select *\nfrom data.csv\n",";"],
        ]
        test_array.each do |_test_|
            puts "/!\\ Testing SELECT against #{_test_}:\n\n"
            MySqliteInstance.any_instance.stubs(:__get_input__).returns(*_test_, *quit)
            sqlite_instance = MySqliteInstance.new
            result = sqlite_instance.instanciation
            puts "\n\n"
        end        
    end

    def test_cli_update
        quit = ["quit",";"]
        test_array = [
            ["update data.csv","set job = пенсионер","where job = Engineer",";"],
            ["update data.csv","set job = пенсионер","age = 20",";"],
            ["update data.csv","set job = пенсионер",";"]
        ]
        test_array.each do |_test_|
            puts "/!\\ Testing UPDATE against #{_test_}:\n\n"
            MySqliteInstance.any_instance.stubs(:__get_input__).returns(*_test_, *quit)
            sqlite_instance = MySqliteInstance.new
            result = sqlite_instance.instanciation
            puts "\n\n"
        end
    # assert_equal 'stubbed value', result
    end
```
## Usage