# Usage

* dictionary to json

```py
import json

my_dict = {"id": 1, "string": "test"}
output_json = json.dumps(my_dict)

# type: json
print(output_json)
```

* json to dictionary

```py
import json

json_str = '{"id": 1, "string": "test"}'
output_dict = json.loads(json_str)

# type: dictionary
print(output_dict)
```
