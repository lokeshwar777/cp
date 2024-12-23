#include <string>
#include <ctime>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Product {
    int product_id;
    string product_name;
    string product_category;
};

struct Order {
    int order_id;
    int product_id;
    int quantity;
    string customer_id;
    time_t order_date;
};

int main() {

    vector<Product> products = {
        {1, "ipad mini", "tablets"},
        {2, "iphone 17 pro max", "mobiles"},
        {3, "microsoft surface", "laptops"},
        {4, "macbook m4 pro", "laptops"},
        {5, "iqoo z5", "mobiles"},
        {6, "swiss military veryfit", "smartwatches"},
        {7, "totulife", "powerbanks"},
    };

    deque<string> recent_customers = {"D1", "D2", "D3", "D4", "D5"};
    recent_customers.push_back("D6");
    recent_customers.push_front("D0");

    list<Order> order_history;

    order_history.push_back({101,1, 3, "D2", time(0)});
    order_history.push_back({102,2, 2, "D4", time(0)});
    order_history.push_back({103,3, 4, "D6", time(0)});

    set<string> categories;

    // for (Product product : products) {
    for (const auto &product: products) {
        categories.insert(product.product_category);
    }

    // for (const auto category : categories) cout << category << endl;

    // ordered map uses binary search tree behind the scenes
    map<int, int> product_stock = {
        {1,23},
        {2,4},
        {3,12},
        {4,6},
        {5,9},
        {6,26},
        {7,7},
    };

    multimap<string, Order> customer_orders;
    for (const auto &order: order_history) {
        customer_orders.insert({order.customer_id, order});
    }

    unordered_map<string, string> customer_data = {}; // TODO

    unordered_set<int> unique_product_ids = {};
    for (const auto &product: products) {
        unique_product_ids.insert(product.product_id);
    }

    return 0;
}