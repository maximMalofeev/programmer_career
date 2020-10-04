#pragma once
#include <list>
#include <map>
#include <set>
#include <string>

struct node {
  std::string name_;
  std::set<std::string> children_;
};

class graph {
 public:
  void append_node(const std::string& name) { nodes_.insert(name, {name}); }

  void connect_nodes(const std::string& node,
                     const std::list<std::string>& nodes) {
    auto target = nodes_.find(node);
    if (target == nodes_.end()) {
      return;
    }

    for (const auto& n : nodes) {
      target->second.children_.insert(n);
    }
  }

 private:
  std::map<std::string, node> nodes_;
};