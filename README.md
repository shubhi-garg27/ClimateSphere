# ClimateSphere

### Personalized Indoor Comfort Through Thread, Matter, and Edge Intelligence

---

## 1. Project Overview

### Description

ClimateSphere is a human-centric IoT platform designed to create personalized micro-climate zones within shared indoor environments such as offices, classrooms, libraries, co-working spaces, and smart homes.

Traditional HVAC and lighting systems treat an entire room as a single environmental zone, often resulting in occupant discomfort and unnecessary energy consumption. ClimateSphere addresses this challenge by continuously monitoring environmental conditions and occupancy patterns across multiple locations within a room.

Using Silicon Labs EFR32MG24-based Thread sensor nodes, the system collects real-time temperature, humidity, ambient light, and occupancy data. This information is transmitted through a self-healing Thread mesh network to an EFR32MG26 Edge Controller. The controller analyzes environmental conditions and user behavior to determine optimal comfort settings and automatically adjusts localized airflow, lighting intensity, and ventilation direction through Matter-enabled devices.

The result is a personalized comfort experience that improves occupant well-being while reducing overall energy consumption.

---

### Why ClimateSphere?

In shared indoor spaces, different people often have different comfort preferences.

Examples:

* One employee may feel warm while another feels cold.
* A student reading a book may require brighter lighting than a student working on a laptop.
* Large sections of a room may remain unoccupied while HVAC systems continue conditioning the entire space.

ClimateSphere creates localized environmental zones around occupied users, ensuring comfort where it is needed while avoiding energy waste in unused areas.

---

### Real-World Use Cases

#### Smart Office

In a modern open-plan office:

| Workspace | Occupancy | Preference         | Action                     |
| --------- | --------- | ------------------ | -------------------------- |
| Desk A    | Occupied  | Cooler Environment | Increase Fan Speed         |
| Desk B    | Occupied  | Standard Comfort   | Maintain Settings          |
| Desk C    | Vacant    | N/A                | Disable Local Conditioning |

Instead of cooling the entire office uniformly, ClimateSphere provides localized comfort around occupied workstations.

---

#### Library Study Area

Different students have different lighting requirements.

**Example:**

* Reading Desk → 800 Lux
* Laptop Workspace → 400 Lux
* Empty Workspace → Lights Dimmed

ClimateSphere automatically adjusts lighting based on occupancy and activity.

---

#### Smart Classroom

During lectures:

* Most seats are occupied.
* Additional ventilation may be required.

During breaks:

* Large portions of the classroom become vacant.

ClimateSphere dynamically adapts airflow and environmental controls according to occupancy levels.

---

#### Home Office

A remote worker occupies a desk area while the rest of the room remains unused.

**Example Workflow**

1. Occupancy detected.
2. Temperature measured at 27°C.
3. Preferred comfort temperature is 24°C.
4. Local fan activated.
5. Personalized comfort zone created.

The entire room does not need to be cooled, reducing energy consumption.

---

### Key Features

* Personalized micro-climate zones
* Occupancy-aware environmental control
* Thread mesh networking
* Matter interoperability
* Adaptive lighting control
* Localized airflow management
* Real-time environmental monitoring
* Energy optimization analytics
* Edge intelligence-based decision making

---

### Project Objectives

* Deliver personalized environmental comfort.
* Reduce energy consumption through localized environmental control.
* Demonstrate Thread mesh networking using Silicon Labs wireless SoCs.
* Enable Matter interoperability across connected devices.
* Implement occupancy-aware automation.
* Provide real-time environmental analytics.
* Showcase practical edge intelligence for smart-building applications.

---


ClimateSphere transforms environmental sensing into intelligent comfort management, delivering a better user experience while reducing unnecessary energy consumption.
