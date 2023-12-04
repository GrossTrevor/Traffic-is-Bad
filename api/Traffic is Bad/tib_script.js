const map = L.map('map').setView([37.8, -96], 4);

const tiles = L.tileLayer('https://tile.openstreetmap.org/{z}/{x}/{y}.png', {
    maxZoom: 19,
    attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
}).addTo(map);

// control that shows state info on hover
const info = L.control();

info.onAdd = function (map) {
    this._div = L.DomUtil.create('div', 'info');
    this.update();
    return this._div;
};

info.update = function (props) {
    const contents = props ? `<b>${props.COUNTY}, ${props.STATE}</b><br />
                              Average crash severity: ${props.SEVERITY}<br />
                              Crossing: ${props.CROSSING}<br />
                              Junction: ${props.JUNCTION}<br />
                              Signal: ${props.SIGNAL}<br />
                              Stop: ${props.STOP}<br />
                              Day: ${props.DAY}<br />
                              Night: ${props.NIGHT}<br />
                              Poor Visibility: ${props.POOR_VISIBILITY}<br />
                              Fair (Weather): ${props.WFAIR}<br />
                              Cloudy (Weather): ${props.WCLOUDY}<br />
                              Foggy (Weather): ${props.WFOG}<br />
                              Rainy (Weather): ${props.WRAIN}<br />
                              Snowy (Weather): ${props.WSNOW}<br />` : 'Hover over a county';
    this._div.innerHTML = `<h4>Information Panel</h4>${contents}`;
};

info.addTo(map);

function highlightFeature(e) {
    const layer = e.target;

    layer.setStyle({
        weight: 3,
        color: '#666',
        dashArray: '',
        fillOpacity: 0.7
    });

    layer.bringToFront();

    info.update(layer.feature.properties);
}

/* global statesData */
var geojson = L.geoJson(county_data, {
    style: function (feature) {
        return {
            weight: 1,
            opacity: 1,
            color: 'white',
            dashArray: '3',
            fillOpacity: 0.7,
            fillColor: getColorSeverity(parseFloat(feature.properties.SEVERITY)) };
    },
    onEachFeature
}).addTo(map);

function resetHighlight(e) {
    geojson.resetStyle(e.target);
    info.update();
}

function zoomToFeature(e) {
    map.fitBounds(e.target.getBounds());
}

function onEachFeature(feature, layer) {
    layer.on({
        mouseover: highlightFeature,
        mouseout: resetHighlight,
        click: zoomToFeature
    });
}

map.attributionControl.addAttribution('Crash data CC BY-NC-SA 4.0; <a href="https://www.kaggle.com/datasets/sobhanmoosavi/us-accidents/data">Sobhan Moosavi</a>');

function resetMap() {
    map.setView([37.8, -96], 4);
}

function filterMap(prop) {
    if (prop == 'SEVERITY') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorSeverity(parseFloat(feature.properties.SEVERITY))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'CROSSING') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorCrossing(parseFloat(feature.properties.CROSSING))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'JUNCTION') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorJunction(parseFloat(feature.properties.JUNCTION))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'SIGNAL') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorSignal(parseFloat(feature.properties.SIGNAL))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'STOP') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorStop(parseFloat(feature.properties.STOP))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'DAY') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorDay(parseFloat(feature.properties.DAY))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'NIGHT') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorNight(parseFloat(feature.properties.NIGHT))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'POOR_VISIBILITY') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorPoorVisibility(parseFloat(feature.properties.POOR_VISIBILITY))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'WFAIR') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorFair(parseFloat(feature.properties.WFAIR))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'WCLOUDY') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorCloudy(parseFloat(feature.properties.WCLOUDY))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'WFOG') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorFoggy(parseFloat(feature.properties.WFOG))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'WRAIN') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorRainy(parseFloat(feature.properties.WRAIN))
                };
            },
            onEachFeature
        }).addTo(map);
    }
    else if (prop == 'WSNOW') {
        geojson.removeFrom(map);
        geojson = L.geoJson(county_data, {
            style: function (feature) {
                return {
                    weight: 1,
                    opacity: 1,
                    color: 'white',
                    dashArray: '3',
                    fillOpacity: 0.7,
                    fillColor: getColorSnowy(parseFloat(feature.properties.WSNOW))
                };
            },
            onEachFeature
        }).addTo(map);
    }
 }


// get color depending on filter factor value
function getColorSeverity(d) {
    return d > 3.9 ? '#c70505' :
           d > 3.5 ? '#c73605' :
           d > 3.2 ? '#c76605' :
           d > 3 ? '#c79605' :
           d > 2.5 ? '#c7c705' :
           d > 2.3 ? '#96c705' :
           d > 2.1 ? '#66c705' :
           d > 2 ? '#36c705' :
           d > 1.5 ? '#05c705' :
           d > 1 ? '#05c736' : '#D3D3D3';
}

function getColorCrossing(d) {
    return d > 10000 ? '#410b2d' :
           d > 3000 ? '#6c134c' :
           d > 1000 ? '#981b6a' :
           d > 300 ? '#c32288' :
           d > 100 ? '#dd3ca2' :
           d > 50 ? '#e467b6' :
           d > 10 ? '#ec93cb' :
           d > 1 ? '#f4bee0' : '#D3D3D3';
}

function getColorJunction(d) {
    return d > 10000 ? '#159d8b' :
           d > 3000 ? '#18b49f' :
           d > 1000 ? '#1ccab3' :
           d > 300 ? '#1fe0c7' :
           d > 100 ? '#35e3cc' :
           d > 50 ? '#62ead7' :
           d > 10 ? '#8ff0e3' :
           d > 1 ? '#bcf6ee' : '#D3D3D3';
}

function getColorSignal(d) {
    return d > 400 ? '#037c50' :
           d > 200 ? '#049560' :
           d > 100 ? '#04ae70' :
           d > 30 ? '#05c780' :
           d > 15 ? '#06f9a0' :
           d > 5 ? '#38fab3' :
           d > 1 ? '#6afbc6' : '#D3D3D3';
}

function getColorStop(d) {
    return d > 10000 ? '#770808' :
           d > 3000 ? '#8f0a0a' :
           d > 1000 ? '#bf0d0d' :
           d > 300 ? '#d70f0f' :
           d > 100 ? '#ee1111' :
           d > 50 ? '#f24040' :
           d > 10 ? '#f57070' :
           d > 1 ? '#f8a0a0' : '#D3D3D3';
}

function getColorDay(d) {
    return d > 20000 ? '#2c2807' :
           d > 10000 ? '#423b0b' :
           d > 3000 ? '#584f0e' :
           d > 1000 ? '#6e6312' :
           d > 300 ? '#847715' :
           d > 100 ? '#9a8b19' :
           d > 50 ? '#af9e1d' :
           d > 10 ? '#c5b220' :
           d > 1 ? '#dbc624' : '#D3D3D3';
}

function getColorNight(d) {
    return d > 10000 ? '#5e0878' :
           d > 3000 ? '#700990' :
           d > 1000 ? '#830ba8' :
           d > 300 ? '#960cc0' :
           d > 100 ? '#bb0ff0' :
           d > 50 ? '#d057f4' :
           d > 10 ? '#dd87f7' :
           d > 1 ? '#e49ff9' : '#D3D3D3';
}

function getColorPoorVisibility(d) {
    return d > 9.5 ? '#2b4422' :
           d > 9 ? '#4c773c' :
           d > 8.5 ? '#61994d' :
           d > 8 ? '#7bb266' :
           d > 7 ? '#89bb77' :
           d > 5 ? '#98c388' :
           d > 3 ? '#a7cc99' :
           d > 1 ? '#c4ddbb' : '#D3D3D3';
}

function getColorFair(d) {
    return d > 10000 ? '#784508' :
           d > 3000 ? '#905309' :
           d > 1000 ? '#a8610b' :
           d > 300 ? '#c06f0c' :
           d > 100 ? '#d87d0e' :
           d > 50 ? '#f19627' :
           d > 10 ? '#f4ae57' :
           d > 1 ? '#f7c587' : '#D3D3D3';
}

function getColorCloudy(d) {
    return d > 50000 ? '#000000' :
           d > 30000 ? '#0d0d0d' :
           d > 20000 ? '#1a1a1a' :
           d > 1000 ? '#333333' :
           d > 300 ? '#4d4d4d' :
           d > 100 ? '#666666' :
           d > 50 ? '#737373' :
           d > 10 ? '#808080' :
           d > 1 ? '#8c8c8c' : '#D3D3D3';
}

function getColorFoggy(d) {
    return d > 1000 ? '#201913' :
           d > 300 ? '#413225' :
           d > 100 ? '#614b38' :
           d > 50 ? '#927154' :
           d > 10 ? '#b5977d' :
           d > 1 ? '#c7b19e' : '#D3D3D3';
}

function getColorRainy(d) {
    return d > 1000 ? '#08225e' :
           d > 300 ? '#0c338d' :
           d > 100 ? '#1044bc' :
           d > 50 ? '#1455eb' :
           d > 10 ? '#4377ef' :
           d > 1 ? '#8aaaf5' : '#D3D3D3';
}

function getColorSnowy(d) {
    return d > 300 ? '#24423f' :
           d > 200 ? '#2d534f' :
           d > 100 ? '#36635f' :
           d > 50 ? '#47857e' :
           d > 30 ? '#59a69e' :
           d > 1 ? '#7ab8b1' : '#D3D3D3';
}

fetch("input_clock.txt")
    .then(function (res) {
        return res.text();
    })
    .then(function (data) {
        document.getElementById("input_clock").innerHTML = "C++ Data Input Time: " + data + " seconds";
    });

fetch("output_clock.txt")
    .then(function (res) {
        return res.text();
    })
    .then(function (data) {
        document.getElementById("output_clock").innerHTML = "C++ Data Output Time: " + data + " seconds";
    });