#include <iostream>
#include <memory>
#include "date.h"
#include "node.h"

using namespace std;

bool EmptyNode::Evaluate(const Date &date, const string &event) const {
    return true;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &o, const shared_ptr<Node> &l,
                                           const shared_ptr<Node> r) : logical_operation(o), left(l), right(r) { }

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const {
    switch(logical_operation) {
        case LogicalOperation::And :
            return left -> Evaluate(date, event) && right -> Evaluate(date, event);
        case LogicalOperation::Or :
            return left -> Evaluate(date, event) || right -> Evaluate(date, event);
    }
}

EventComparisonNode::EventComparisonNode(const Comparison &c, const string &e) : comp(c), event(e) {}

bool EventComparisonNode::Evaluate(const Date &date_to_compare, const string &event_to_compare) const {
    switch(comp) {
        case Comparison::Equal:
            return event_to_compare == event;
        case Comparison::Greater :
            return event_to_compare > event;
        case Comparison::GreaterOrEqual :
            return event_to_compare >= event;
        case Comparison::Less :
            return event_to_compare < event;
        case Comparison::LessOrEqual :
            return event_to_compare <= event;
        case Comparison::NotEqual :
            return event_to_compare != event;
    }
}

DateComparisonNode::DateComparisonNode(const Comparison &c, const Date &d) : comp(c), date(d) {}

bool DateComparisonNode::Evaluate(const Date &date_to_compare, const string &event_to_compare) const {
    switch(comp) {
        case Comparison::Equal:
            return date_to_compare == date;
        case Comparison::Greater :
            return date_to_compare > date;
        case Comparison::GreaterOrEqual :
            return date_to_compare >= date;
        case Comparison::Less :
            return date_to_compare < date;
        case Comparison::LessOrEqual :
            return date_to_compare <= date;
        case Comparison::NotEqual :
            return date_to_compare != date;
    }
}