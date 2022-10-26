# Master Workspace

Colcon workspace for master thesis project code, by nthom18.

---
> :warning: Submodules might not be included if not cloned this way.
Clone this repository with ssh and all submodules with:
```
git clone --recurse-submodules git@github.com:PositiveBeat/nthom18-master-workspace.git
```

> :warning: The branch tag in `.gitmodules` does not seem to take affect, change this branch manually with:
```
cd nthom18-master-workspace/src/swarm_behaviours/external/swarm-simulator/
git checkout nthom18-dev 
```

> :flags: In case VScode intellisense is compaining about missing headers for the submodule includes, a copy of a `c_cpp_properties.json` file is included in the repo for reference. 