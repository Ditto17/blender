#pragma once

#include <functional>

#include "BKE_node_tree.hpp"
#include "FN_data_flow_nodes.hpp"

#include "world_state.hpp"
#include "step_description.hpp"
#include "forces.hpp"

namespace BParticles {

using BKE::bSocketList;
using BKE::IndexedNodeTree;
using BKE::SocketWithNode;
using FN::DataFlowNodes::BTreeDataGraph;

struct BuildContext {
  IndexedNodeTree &indexed_tree;
  BTreeDataGraph &data_graph;
  ModifierStepDescription &step_description;
  WorldState &world_state;
};

using ForceFromNodeCallback =
    std::function<std::unique_ptr<Force>(BuildContext &ctx, bNode *bnode)>;
using ForceFromNodeCallbackMap = SmallMap<std::string, ForceFromNodeCallback>;

ForceFromNodeCallbackMap &get_force_builders();

using EventFromNodeCallback =
    std::function<std::unique_ptr<Event>(BuildContext &ctx, bNode *bnode)>;
using EventFromNodeCallbackMap = SmallMap<std::string, EventFromNodeCallback>;

EventFromNodeCallbackMap &get_event_builders();

using EmitterFromNodeCallback = std::function<std::unique_ptr<Emitter>(
    BuildContext &ctx, bNode *bnode, StringRef particle_type_name)>;
using EmitterFromNodeCallbackMap = SmallMap<std::string, EmitterFromNodeCallback>;

EmitterFromNodeCallbackMap &get_emitter_builders();

}  // namespace BParticles