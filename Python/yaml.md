# Usage

The format of YAML should be "key: value" not "key:value".

The space is important.

* dictionary to yaml

```py
import yaml
yaml_dict = {"key1": "value1", "list2": ["a", "b", "c"]}
print(yaml.dump(yaml_dict))
```

* yaml to dictionary

```py
import yaml
# Note: space should be after ':', or you'll have parse error.
yaml_string = "key1: value1\nkey2: value2\n"
mydict = yaml.safe_load(yaml_string)
# dictionary
print(type(mydict))
# {'key1': 'value1', 'key2': 'value2'}
print(mydict)
```

* yaml to file

```py
import yaml
with open("my.yaml", "w") as f:
    yaml_dict = {"key1": "value1", "list2": ["a", "b", "c"]}
    yaml.dump(yaml_dict, f)
```

* file to yaml

```py
import yaml
with open("my.yaml") as f:
    myyaml = yaml.safe_load(f)
    print(myyaml)
```
