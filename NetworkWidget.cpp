#include "NetworkWidget.hpp"

#include "imgui.h"
#include "imgui_stdlib.h"

void NetworkWidget::draw() {
	bool isConnected = (socket.getRemoteAddress() != sf::IpAddress::None);

	ImGui::Begin("Network", nullptr, ImGuiWindowFlags_AlwaysAutoResize);

	ImGui::Text("Ip Address");
	ImGui::InputText("##ipInput", &ipInput);
	ImGui::Spacing();
	ImGui::Text("Port");
	ImGui::InputInt("##portInput", &portInput, 0, 0);
	ImGui::Separator();
	ImGui::Text("Connection established: %s", isConnected ? "true" : "false");

	if(ImGui::Button("Connect") && !isConnected) {
		// todo: maybe handle connection somewhere else, this widget has too many responsibilities
		status = socket.connect(ipInput, portInput);
	}

	if(status == sf::Socket::Error) {
		ImGui::SameLine();
		ImGui::Text("Could not connect!");
	}

	ImGui::End();
}